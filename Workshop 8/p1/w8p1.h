#define MAX_NUM_PRODUCTS 3
#define GRAMS_PER_SERVING 64

struct CatFoodInfo
{
    int main;       //main
    double price;  //price
    int calorie; //calories
    double weight;  //weight
};

int getIntPositive(int* i); 

double getDoublePositive(double* d);

void openingMessage(const int); \

struct CatFoodInfo getCatFoodInfo(const int);

void displayCatFoodHeader();

void displayCatFoodData(int, double*, int, double*);

void start();