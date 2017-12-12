import sys

curselected = None
current_oid = None
current_count = 0

for line in sys.stdin:
    line = line.strip();
    selected, oid, count = line.split('\t')

    try:
        count = int(count)
    except ValueError:
        continue

    if current_oid == oid and curselected == selected:
        current_count += count
    else:
        if current_oid and curselected:
            print "%s\t%s\t%s" % (curselected, current_oid, current_count)
        current_count = count
        current_oid = oid
        curselected = selected


if current_oid == oid and curselected == selected:
    print "%s\t%s\t%s" % (curselected, current_oid, current_count)
