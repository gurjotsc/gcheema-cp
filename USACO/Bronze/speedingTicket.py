with open('speeding.in') as read:
	road_seg_num, speed_seg_num = [int(i) for i in read.readline().split()] #inputs the number of segments on the road and their speed as well as the number of bessies segments
	limit_segs = [[int(i) for i in read.readline().split()] #input the segment length and speed for limits
				   for _ in range(road_seg_num)]

	bessie_segs = [[int(i) for i in read.readline().split()] #input the segment length and speed for bessie
					for _ in range(speed_seg_num)]

limit = []
for s in limit_segs:
	for _ in range(s[0]):
		limit.append(s[1]) #The array will have 100 elements, one for each mile and you store the speed limit for that mile
bessie = []
for s in bessie_segs:
	for _ in range(s[0]):
		bessie.append(s[1]) #The array will have 100 elements, one for each mile and you store bessies speed limit for that mile

worst = 0
for a, b in zip(limit, bessie):
	worst = max(worst, b - a) #Find the biggest speed discrepency
print(worst, file=open('speeding.out', 'w'))
