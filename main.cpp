/*Class 351
 Mohammed Hassnain
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <thread>
#include <iostream>

#define Size 2
#define PRIME 4
#define NOPRIME 2
#define SIZE 18


#define STUDENT_NAME "Mohammed Hassnain"
#define STUDENT_CWID "894088921"

using namespace std;

bool test = false;


//Do not edit code in this section:
void print_name(void) {
	printf("\n%s\n", STUDENT_NAME);
	printf("%s\n", STUDENT_CWID);
}


int is_prime(long long num)
{
	if (num <= 1) return 0;
	if (num % 2 == 0 && num > 2) return 0;
	for (long long i = 3; i < num / 2; i += 2)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}
//end of section

void* runner(void *arg)
{

	char buffer[SIZE];
	int c = 0;
	int i = 0;
	int z = 0;
	int h;

	do {

		if (test == true)
			break;

		if (c != EOF)
		{


			c = getchar();


			if (isspace(c)) {
				buffer[i] = '\0';
				i = 0;
			}
			else if (isdigit(c)) {
				buffer[i] = c;
				i++;
			}

			if (i == SIZE) {
				buffer[i] = '\0';
				i = 0;
			}
			if (i == 0 && strnlen(buffer, SIZE) > 0) {

				puts(buffer);


				if (is_prime(atoll(buffer)))
				{
					cout << "Prime found, return value: " << PRIME << " Number is: " << atoll(buffer) << endl;
					test = true;
					// exit(0);
				 //   pthread_exit(0);
					break;
				}




			}
			if (test == true)
				break;

		}

	} while ((c != EOF) && !(test == true));

	pthread_exit(0);

}



int main(int argc, char ** argv)
{
	unsigned int n = std::thread::hardware_concurrency();
	printf("Concurrent Threads Supported: %d\n", n);

	//Do not edit the code in this section:
	if (argc == 2 && strncmp(argv[1], "-n", 2) == 0) {
		print_name();
		return 0;
	}
	//end of name print section





	cout << "--------MultiThreaded Programming--------" << endl;



	// Thread ID:
	pthread_t clone[Size];

	// Create attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	for (int i = 0; i < Size; i++)
		pthread_create(&clone[i], &attr, runner, NULL);

	for (int h = 0; h < Size; h++)
		pthread_join(clone[h], NULL);

	// No prime case
	if (test != true)
	{
		cout << "return value: " << NOPRIME << endl;
	}


}
