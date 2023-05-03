bin/proFile: countEmployees.o fireAll.o fireOne.o lookOnFullname.o lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o helperA3.o mainA3.o
	gcc -Wall -g -std=c99 countEmployees.o fireAll.o fireOne.o lookOnFullname.o lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o helperA3.o mainA3.o -o bin/proFile

countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/countEmployees.c

fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/fireAll.c

fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/fireOne.c

lookOnFullname.o: src/lookOnFullname.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/lookOnFullname.c

lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/lookOnId.c

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/printAll.c

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/printOne.c

recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/recruitEmployee.c

sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/sortEmployeesId.c

helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/helperA3.c

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -g -std=c99 -c src/mainA3.c

clean:
	rm *.o bin/proFile