public interface Step<I, O> {
    public static class StepException extends RuntimeException {
        public StepException(Throwable t) {
            super(t);   
        }
    }
    public O process(I input) throws StepException;
}

public class Pipeline<I, O> {
    private final Step<I, O> current;
    private Pipeline(Step<I, O> current) {
        this.current = current;
    }

    private <NewO> Pipeline<I, NewO> pipe(Step<O, NewO> next) {
        return new Pipeline<>(input -> next.process(current.process(input)));
    }
    
    public O execute(I input) throws Step.StepException {
        return current.process(input);
    }
}

public class ExamplePipeline {
    public static class AdditionInput {
        public final int int1;
        public final int int2;
        
        public AdditionInput(int int1, int int2) {
            this.int1 = int1;
            this.int2 = int2;
        }
    }
    public static class AddIntegersStep implements Step<AdditionInput, Integer> {
        public Integer process(AdditionInput input) {
            return input.int1 + input.int2;   
        }
    }
    
    public static class IntToStringStep implements Step<Integer, String> {
        public String process(Integer input) {
            return input.toString();
        }
    }
    
    public static void main(String[] args) {
        Pipeline<AdditionInput, String> pipeline = new Pipeline<>(new AddIntegersStep())
            .pipe(new IntToStringStep());
        System.out.println(pipeline.execute(new AdditionInput(1, 3))); // outputs 4
    }
}
