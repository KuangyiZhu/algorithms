import sys

for line in sys.stdin:
  line = line.strip();
  fields = line.split('\t');
  selected = fields[2];

  fields2 = selected.split(';')
  for i, field2 in enumerate(fields2):
      if(i < len(fields2) - 1):
          (oid, reason) = field2.split(',')
          print "1\t%s\t1" % oid

  if(len(fields) >= 4):
      deselected = fields[3];
      fields3 = deselected.split(';')
      for i, field3 in enumerate(fields3):
        if(i < len(fields3) - 1):
          (oid, reason) = field3.split(',')
          print "0\t%s\t1" % oid
