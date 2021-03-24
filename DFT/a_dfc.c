#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <math.h>
#include <dfc.h>

int DF_fanout_di = 0;
int DF_persize_di;
DF_AD DF_AD_di;

double di[1];

int DF_fanout_ci2 = 1;
int DF_persize_ci2;
DF_AD DF_AD_ci2;

int DF_fanout_ci1 = 1;
int DF_persize_ci1;
DF_AD DF_AD_ci1;

int DF_fanout_d2 = 1;
int DF_persize_d2;
DF_AD DF_AD_d2;

int DF_fanout_d1 = 1;
int DF_persize_d1;
DF_AD DF_AD_d1;

DF_FN DF_FN_C;
DF_FN DF_FN_B;
DF_FN DF_FN_A;
DF_FN DF_FN_F;
DF_TFL DF_TFL_TABLE;

FILE *fp_sche = NULL;

pthread_mutex_t sched_info_mutex;

struct timeval program_start;
struct timeval program_end;

double difftimeval(const struct timeval *start, const struct timeval *end)
{
    double d;
    time_t s;
    suseconds_t u;

    s = start->tv_sec - end->tv_sec;
    u = start->tv_usec - end->tv_usec;
    //if (u < 0)
    //        --s;

    d = s;
    d *= 1000000.0; //1 秒 = 10^6 微秒
    d += u;

    return d;
}

void F(/* DF-C function */)
{
    int DF_count;

    double d2;

    DF_persize_d2 = sizeof(d2);
    double d1;

    DF_persize_d1 = sizeof(d1);
    DF_SOURCE_Get_And_Update(&DF_FN_F, &DF_count);
    {
        for (size_t i = 0; i < 100; i++)
        {
            d1 = 3.0;
            d2 = 4.0;
            d1 = cos(d1);
            d2 = cos(d2);
        }

        printf("case #%d F uid: %d\n", DF_count, gettid());
        d1 = 3.0;
        d2 = 4.0;
        printf("d1: %.02f\n", d1);
        printf("d2: %.02f\n", d2);
    }
    // printf_thread_info(&DF_TFL_TABLE);

    DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_F, &d2, DF_persize_d2, &d1, DF_persize_d1);
    // printf_thread_info(&DF_TFL_TABLE);
}

void A(/* DF-C function */)
{
    double d1;

    DF_persize_d1 = sizeof(d1);
    double ci1;
    printf_thread_info(&DF_TFL_TABLE);

    DF_persize_ci1 = sizeof(ci1);
    int DF_count = DF_AD_GetData(&DF_FN_A, &d1, DF_persize_d1);
    {
        printf("case #%d A uid: %d\n", DF_count, gettid());
        ci1 = d1;
        for (int i = 0; i < 100; i++)
        {
            ci1 = cos(ci1);
        }
        ci1 = d1 * d1;
    }
    // printf_thread_info(&DF_TFL_TABLE);

    DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_A, &ci1, DF_persize_ci1);
    // printf_thread_info(&DF_TFL_TABLE);

}

void B(/* DF-C function */)
{
    double d2;

    DF_persize_d2 = sizeof(d2);
    double ci2;

    DF_persize_ci2 = sizeof(ci2);
    printf_thread_info(&DF_TFL_TABLE);

    int DF_count = DF_AD_GetData(&DF_FN_B, &d2, DF_persize_d2);
    {
        printf("case #%d B uid: %d\n", DF_count, gettid());
        ci2 = d2;
        for (int i = 0; i < 100; i++)
        {
            ci2 = cos(ci2);
        }
        ci2 = d2 * d2;
    }

    DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_B, &ci2, DF_persize_ci2);

}

void C(/* DF-C function */)
{
    double ci2;

    DF_persize_ci2 = sizeof(ci2);
    double ci1;

    DF_persize_ci1 = sizeof(ci1);
    double di;

    DF_persize_di = sizeof(di);
    int DF_count = DF_AD_GetData(&DF_FN_C, &ci2, DF_persize_ci2, &ci1, DF_persize_ci1);
    {
        printf("case #%d C uid: %d\n", DF_count, gettid());
        di = ci1 + ci2;
        printf("di: %f\n", di);
    }
    DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_C, &di, DF_persize_di);
    // printf_thread_info(&DF_TFL_TABLE);

}

double __original_main()
{
    srand(time(0));
    DF_Run(&DF_TFL_TABLE, 1);
    return (0);
}

/* DF-C-generated main() */
int main(int argc, char **argv)
{
    gettimeofday(&program_start, NULL);
    // fp_sche = fopen("./sched_info.txt", "w+");
    pthread_mutex_init(&sched_info_mutex, NULL);
    DF_ADInit(&DF_AD_di, sizeof(double), DF_fanout_di);
    DF_ADInit(&DF_AD_ci2, sizeof(double), DF_fanout_ci2);
    DF_ADInit(&DF_AD_ci1, sizeof(double), DF_fanout_ci1);
    DF_ADInit(&DF_AD_d1, sizeof(double), DF_fanout_d1);
    DF_ADInit(&DF_AD_d2, sizeof(double), DF_fanout_d2);

    DF_FNInit1(&DF_FN_C, &C, "C", 2, &DF_AD_ci2, &DF_AD_ci1);
    DF_FNInit2(&DF_FN_C, 1, &DF_AD_di);
    DF_FNInit1(&DF_FN_B, &B, "B", 1, &DF_AD_d2);
    DF_FNInit2(&DF_FN_B, 1, &DF_AD_ci2);
    DF_FNInit1(&DF_FN_A, &A, "A", 1, &DF_AD_d1);
    DF_FNInit2(&DF_FN_A, 1, &DF_AD_ci1);
    DF_FNInit1(&DF_FN_F, &F, "F", 0);
    DF_FNInit2(&DF_FN_F, 2, &DF_AD_d2, &DF_AD_d1);

    DF_SourceInit(&DF_TFL_TABLE, 1, &DF_FN_F);
    DF_Init(&DF_TFL_TABLE, 4, &DF_FN_C, &DF_FN_B, &DF_FN_A, &DF_FN_F);
    DF_OutputInit(&DF_TFL_TABLE, 1, &DF_AD_di);

    // exit(0);

    
    int DF_original_main_ret = (int)__original_main();

    // fclose(fp_sche);
    void **result = DF_Result(&DF_TFL_TABLE);


    gettimeofday(&program_end, NULL);
    printf("time spend: %f\n", difftimeval(&program_end, &program_start));
    return (DF_original_main_ret);
}
