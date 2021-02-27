void F(;double d1, double d2, double ci3, double ci4) {
    printf("case #%d F uid: %d\n", DF_count, gettid());
    d1 = (double)(rand() % 10) + 1;
    d2 = (double)(rand() % 10) + 1;
    ci3 = (double)(rand() % 10) + 1;
    ci4 = (double)(rand() % 10) + 1;
}

void A(double d1; double ci1) {
    printf("case #%d A uid: %d\n", DF_count, gettid());

    ci1 = d1 * d1;
}

void B(double d2; double ci2) {
    printf("case #%d B uid: %d\n", DF_count, gettid());
    ci2 = 1.0 / d2;
}

void C(double ci1, double ci2, double ci3, double ci4; double di) {
    printf("case #%d C uid: %d\n", DF_count, gettid());
    di = ci1 + ci2 + ci3 + ci4;
}

void D(double di; double output) {
    output = - di;
    printf("case #%d D output: %lf\n", DF_count, output);
}

double main()
{
    srand(time(0));
    DF_Run(4);
    // sleep(10);
    return 0;
}