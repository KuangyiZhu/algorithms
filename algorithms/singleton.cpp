	template<typename T> class UploaderFactory {
	public:

		/**
		 * @brief The function to get the instance of the uploader
		 */
		static T * GetInstance() {
			MutexLocker locker(_mutex);
			if(NULL == _p_instance) {
				_p_instance = new T();
				if(RET_SUCC != _p_instance->Init()) {
					return NULL;
				}
			}
			return static_cast<T*>(_p_instance->GetRef());
		}

		/**
		 * @brief The function to release the instance
		 */
		static void Release() {
			MutexLocker locker(_mutex);
			if(NULL != _p_instance) {
				long cur_count = _p_instance->QueryRefCount();
				_p_instance->Release();
				if(cur_count <= 1) {
					_p_instance = NULL;
				}
			}
		}
	private:
		static T * _p_instance;
		static SimpleMutex _mutex;

	};

	//initializing the static members
	template<typename T> T * UploaderFactory<T>::_p_instance = NULL;
	template<typename T> SimpleMutex UploaderFactory<T>::_mutex;

	/**
	 * @class UploaderSmartPtr
	 * Smart Pointer for uploaders
	 */
	template<typename T>
	class UploaderSmartPtr {
	public:
		UploaderSmartPtr() {_ptr = UploaderFactory<T>::GetInstance();};
		~UploaderSmartPtr() { _ptr = NULL; UploaderFactory<T>::Release();}
		T * operator->() const {return _ptr;}
	private:
		T * _ptr;
	};

	/**
	 * @class AbstractUploader
	 * The framework to do the uploading
	 */
	class AbstractUploader {
	public:

	    /**
	     * Constructor
	     */
		AbstractUploader();

	    /**
	     * Destructor
	     */
		virtual ~AbstractUploader();

		/**
		 * @brief The initializer
		 */
		virtual RET_CODE Init();

		/**
		 * @brief Add data
		 *
		 * @param[in] string & str: the string to be uploaded
		 */
		virtual void AddData(string & str);

		/**
		 * @brief Get the current object
		 *
		 * @return AbstractUploader* : the pointer to the current object
		 */
		virtual AbstractUploader * GetRef();

		/**
		 * @brief Check the reference counter
		 *
		 * @return long: the reference count
		 */
		virtual long QueryRefCount() const;

		/**
		 * @brief Release the current reference
		 */
		virtual void Release();
	protected:

		/* The function handler to process the uploading operation*/
		Closure<bool, vector<string>& >* _processor;

		/* The dataflow object to process data*/
		DataflowBase<string>* _dataflow;

		/* Reference counter */
		Atomic<long> refcount;

		/*
		 * @brief Actual function to write to the output
		 */
		virtual bool Write(vector<string> & str_vec) = 0;

		/*
		 * @brief Function to hook the processor
		 */
		virtual void HookProcessor() = 0;
	};

	/**
	 * @class FileUploader
	 * The uploader to write the output into files
	 */
	class FileUploader : public AbstractUploader {
	public:

		/**
		 * @brief The initializer
		 */
		virtual RET_CODE Init();

	    /**
	     * Constructor
	     */
		FileUploader();

	    /**
	     * Destructor
	     */
		virtual ~FileUploader();
	protected:
		/*
		 * @brief Actual function to write to the output
		 */
		virtual bool Write(vector<string> & str_vec) {
			for(vector<string>::iterator it = str_vec.begin(); it != str_vec.end(); ++it)
				_fout << *it;
			return true;
		}

		/*
		 * @brief Function to hook the processor
		 */
		virtual void HookProcessor();
	private:
		/* the output stream*/
		ofstream _fout;
	};

	/**
	 * @class UdpUploader
	 * The uploader to upload to udp stream
	 */
	class UdpUploader : public AbstractUploader {
	public:
	    /**
	     * Constructor
	     */
		UdpUploader() : AbstractUploader() {};

		 /**
		  * Destructor
		  */
		virtual ~UdpUploader() { }

		/**
		 * @brief The initializer
		 */
		virtual RET_CODE Init();
	protected:
		/*
		 * @brief Actual function to write to the output
		 */
		virtual bool Write(vector<string> & str_vec) {
			if (str_vec.empty()) {
				_LOG(WARNING) << "Do UpLoadToAgent failed, data_type_values empty.";
				return false;
			}

			vector<string>::iterator iter = str_vec.begin();
			for (; iter != str_vec.end(); ++iter) {
				string &send_data = *iter;
				if (send_data.empty()) {
					continue;
				}
				if (!UdpMsgSenderInstance().SendOneMessage(send_data)) {
					_LOG(WARNING) << "Do UpLoadToAgent failed: " << send_data;
				}
			}

			ThisThread::Sleep(1);
			return true;
		}

		/*
		 * @brief Function to hook the processor
		 */
		virtual void HookProcessor();
	};
}; // end namespace Dumper
