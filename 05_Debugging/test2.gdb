set $i = 0

break range.c:34 if $i++ >= 28 && $i <= 36
	command 1
	printf "@@@ start=%d stop=%d step=%d value=%d \n", start, n, s, m
	continue
end

run
quit

