#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    vector <float> vec;
    struct timespec start, end;

    for (int i = 0; i < 10000; i++) {
#ifndef DEBUG
	clock_gettime(CLOCK_REALTIME, &start);
#endif
	vec.push_back(i);
#ifndef DEBUG
	clock_gettime(CLOCK_REALTIME, &end);
	FILE *fp = fopen("test_data", "a");
	fprintf(fp, "%lu\n", end.tv_nsec - start.tv_nsec);
	fclose(fp);
#endif
    }
    return 0;
}
