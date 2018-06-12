from multiprocessing.dummy import Pool
import random, time

treads=4
popitok=1E8
popodaniy=0
pool=Pool(treads)

def foo(a):
	pom=0
	for i in range(int(popitok/treads)):
		randX=random.random()
		randY=random.random()

		if randX**2+randY**2<=1: pom+=1
	
	return pom

print("Single stream")
startTime=time.time()
for i in range(int(popitok)):
	randX=random.random()
	randY=random.random()

	if randX**2+randY**2<=1: popodaniy+=1

print(4*popodaniy/popitok, time.time()-startTime)
popodaniy=0

print("Multi stream")
startTime=time.time()
pom=pool.map(foo, (666,)*treads)
for x in pom: popodaniy+=x
print(4*popodaniy/popitok, time.time()-startTime)