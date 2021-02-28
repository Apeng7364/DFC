#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <dfc.h>

#include "dft.h"

int DF_fanout_output = 0;
int DF_persize_output;
DF_AD DF_AD_output;

double output[4];

int DF_fanout_di = 1;
int DF_persize_di;
DF_AD DF_AD_di;

int DF_fanout_ci2 = 1;
int DF_persize_ci2;
DF_AD DF_AD_ci2;

int DF_fanout_ci1 = 1;
int DF_persize_ci1;
DF_AD DF_AD_ci1;

int DF_fanout_ci4 = 1;
int DF_persize_ci4;
DF_AD DF_AD_ci4;

int DF_fanout_ci3 = 1;
int DF_persize_ci3;
DF_AD DF_AD_ci3;

int DF_fanout_d2 = 1;
int DF_persize_d2;
DF_AD DF_AD_d2;

int DF_fanout_d1 = 1;
int DF_persize_d1;
DF_AD DF_AD_d1;

DF_FN DF_FN_D;
DF_FN DF_FN_C;
DF_FN DF_FN_B;
DF_FN DF_FN_A;
DF_FN DF_FN_F;
DF_TFL DF_TFL_TABLE;

FILE *fp_sche = NULL;

pthread_mutex_t sched_info_mutex;

struct timeval program_start;

void F(/* DF-C function */)
{
  int DF_count;

  double ci4;
  DF_persize_ci4 = sizeof(ci4);

  double ci3;
  DF_persize_ci3 = sizeof(ci3);

  double d2;
  DF_persize_d2 = sizeof(d2);

  double d1;
  DF_persize_d1 = sizeof(d1);

  DF_SOURCE_Get_And_Update(&DF_FN_F, &DF_count);
  // int DF_FN_item_index = use_funcname_to_get_item_index(&DF_TFL_TABLE, "F");
  {
    printf("case #%d F uid: %d\n", DF_count, gettid());
    d1 = (double)(rand() % 10) + 1;
    d2 = (double)(rand() % 10) + 1;
    ci3 = (double)(rand() % 10) + 1;
    ci4 = (double)(rand() % 10) + 1;
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_F, &ci4, DF_persize_ci4, &ci3, DF_persize_ci3, &d2, DF_persize_d2, &d1, DF_persize_d1);
}


void A(/* DF-C function */)
{
  double d1;

  DF_persize_d1 = sizeof(d1);
  double ci1;

  DF_persize_ci1 = sizeof(ci1);
  int DF_count = DF_AD_GetData(&DF_FN_A, &d1, DF_persize_d1);
  {
    printf("case #%d A uid: %d\n", DF_count, gettid());
    ci1 = d1 * d1;
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_A, &ci1, DF_persize_ci1);
}

void B(/* DF-C function */)
{
  double d2;

  DF_persize_d2 = sizeof(d2);
  double ci2;

  DF_persize_ci2 = sizeof(ci2);
  int DF_count = DF_AD_GetData(&DF_FN_B, &d2, DF_persize_d2);
  {
    printf("case #%d B uid: %d\n", DF_count, gettid());
    ci2 = 1.0 / d2;
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_B, &ci2, DF_persize_ci2);
}

void C(/* DF-C function */)
{
  double ci4;

  DF_persize_ci4 = sizeof(ci4);
  double ci3;

  DF_persize_ci3 = sizeof(ci3);
  double ci2;

  DF_persize_ci2 = sizeof(ci2);
  double ci1;

  DF_persize_ci1 = sizeof(ci1);
  double di;

  DF_persize_di = sizeof(di);
  int DF_count = DF_AD_GetData(&DF_FN_C, &ci4, DF_persize_ci4, &ci3, DF_persize_ci3, &ci2, DF_persize_ci2, &ci1, DF_persize_ci1);
  {
    printf("case #%d C uid: %d\n", DF_count, gettid());
    di = ci1 + ci2 + ci3 + ci4;
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_C, &di, DF_persize_di);
}

void D(/* DF-C function */)
{
  double di;

  DF_persize_di = sizeof(di);
  double output;

  DF_persize_output = sizeof(output);
  int DF_count = DF_AD_GetData(&DF_FN_D, &di, DF_persize_di);
  {
    output = -di;
    printf("case #%d D output: %lf\n", DF_count, output);
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_D, &output, DF_persize_output);
}

double __original_main()
{
  srand(time(0));
  DF_Run(&DF_TFL_TABLE, 4);
  return (0);
}

/* DF-C-generated main() */
int main(int argc, char **argv)
{
  gettimeofday(&program_start, NULL);
  fp_sche = fopen("./sched_info.txt", "w+");
  pthread_mutex_init(&sched_info_mutex, NULL);
  DF_ADInit(&DF_AD_output, sizeof(double), DF_fanout_output);
  DF_ADInit(&DF_AD_di, sizeof(double), DF_fanout_di);
  DF_ADInit(&DF_AD_ci2, sizeof(double), DF_fanout_ci2);
  DF_ADInit(&DF_AD_ci1, sizeof(double), DF_fanout_ci1);
  DF_ADInit(&DF_AD_d1, sizeof(double), DF_fanout_d1);
  DF_ADInit(&DF_AD_d2, sizeof(double), DF_fanout_d2);
  DF_ADInit(&DF_AD_ci3, sizeof(double), DF_fanout_ci3);
  DF_ADInit(&DF_AD_ci4, sizeof(double), DF_fanout_ci4);

  DF_FNInit1(&DF_FN_D, &D, "D", 1, &DF_AD_di);
  DF_FNInit2(&DF_FN_D, 1, &DF_AD_output);
  DF_FNInit1(&DF_FN_C, &C, "C", 4, &DF_AD_ci4, &DF_AD_ci3, &DF_AD_ci2, &DF_AD_ci1);
  DF_FNInit2(&DF_FN_C, 1, &DF_AD_di);
  DF_FNInit1(&DF_FN_B, &B, "B", 1, &DF_AD_d2);
  DF_FNInit2(&DF_FN_B, 1, &DF_AD_ci2);
  DF_FNInit1(&DF_FN_A, &A, "A", 1, &DF_AD_d1);
  DF_FNInit2(&DF_FN_A, 1, &DF_AD_ci1);
  DF_FNInit1(&DF_FN_F, &F, "F", 0);
  DF_FNInit2(&DF_FN_F, 4, &DF_AD_ci4, &DF_AD_ci3, &DF_AD_d2, &DF_AD_d1);

  DF_SourceInit(&DF_TFL_TABLE, 1, &DF_FN_F);
  DF_Init(&DF_TFL_TABLE, 5, &DF_FN_D, &DF_FN_C, &DF_FN_B, &DF_FN_A, &DF_FN_F);
  DF_OutputInit(&DF_TFL_TABLE, 1, &DF_AD_output);
  int DF_original_main_ret = (int)__original_main();
  fclose(fp_sche);
  void **result = DF_Result(&DF_TFL_TABLE);
  return (DF_original_main_ret);
}
