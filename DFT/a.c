#include<math.h>
void F(;double d1, double d2) {
    printf("case #%d F uid: %d\n", DF_count, gettid());
    // d1 = (double)(rand() % 10) + 1;
    // d2 = (double)(rand() % 10) + 1;
    d1 = 3.0;
    d2 = 4.0;
    printf("d1: %.02f\n", d1);
    printf("d2: %.02f\n", d2);
}

void A(double d1; double ci1) {
    printf("case #%d A uid: %d\n", DF_count, gettid());
    ci1 = d1;
    for (int i = 0; i < 1000; i++) {
        ci1 = sin(d1);
    }
}

void B(double d2; double ci2) {
    printf("case #%d B uid: %d\n", DF_count, gettid());
    ci2 = d2;
    for (int i = 0; i < 1000; i++) {
        ci2 = sin(d2);
    }
}

void C(double ci1, double ci2; double di) {
    printf("case #%d C uid: %d\n", DF_count, gettid());
    di = ci1 + ci2;
    printf("di: %f\n", di);
}


double main()
{
    srand(time(0));
    DF_Run(1);
    // sleep(10);
    return 0;
}