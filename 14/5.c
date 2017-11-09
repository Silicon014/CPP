#define CSIZE 4
struct name {
	char firstname[20];
	char lastname[20];
	};
struct student {
	struct name stuname;
	double grade[3];
	double average;
	};
int getdata(struct student [], int);
void average(struct student [], int);
void printdata(struct student [], int);
void totalaverage(struct student [], int);
int main(void)
{
	struct student class[CSIZE];
	
