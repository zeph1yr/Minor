#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int K, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16 ;

int n;
int distance[1000];
int Rank[1000];

int dist (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int Age[1000],Gender[1000],Polyuria[1000],Polydipsia[1000],WeightLoss[1000],Weakness[1000],Polyphagia[1000],GenitalThrush[1000],VisualBlurring[1000],Itching[1000],Irritability[1000],DelayedHealing[1000],PartialParesis[1000],MuscleStiffness[1000],Alopecia[1000],Obesity[1000],Classification[1000];
int distance1[1000];

void KNN()
{
    printf("Nearest 3 neighbors (Including tie)\n");

    int flag=0;

    for(int i = 0 ; i< n ; i++)
    {
        if(Rank[i] < 4 )
        {
            printf("%d ",Classification[i]);

            if(Classification[i])flag++;
            else flag--;
        }
    }
    printf("\n \n");

    if(flag>=0) printf("The patient may have diabetes");
    else printf("The patient may NOT have diabetes");


}

int main()
{
    printf("Gender Polyuria Polydipsia Sudden_Weight_loss Weakness Polyphagia Genital_thrush Visual_blurring Itching Irritability Delayed_healing Partial_paresis Muscle_stiffness Alopecia Obesity\n");

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &x1, &x2, &x3, &x4, &x5, &x6, &x7,
        &x8, &x9, &x10, &x11, & x12, &x13, &x14, &x15, &x16
          );

    freopen("input.txt","r",stdin);

    scanf("%d", &n);
    for( int i = 0 ; i < n; i++ )
    {
        scanf("%d", &Age[i]);
        scanf("%d", &Gender[i]);
        scanf("%d", &Polyuria[i]);
        scanf("%d", &Polydipsia[i]);
        scanf("%d", &WeightLoss[i]);
        scanf("%d", &Weakness[i]);
        scanf("%d", &Polyphagia[i]);
        scanf("%d", &GenitalThrush[i]);
        scanf("%d", &VisualBlurring[i]);
        scanf("%d", &Itching[i]);
        scanf("%d", &Irritability[i]);
        scanf("%d", &DelayedHealing[i]);
        scanf("%d", &PartialParesis[i]);
        scanf("%d", &MuscleStiffness[i]);
        scanf("%d", &Alopecia[i]);
        scanf("%d", &Obesity[i]);
        scanf("%d", &Classification[i]);

    }

     printf("distance\n");
    for(int i = 0 ; i<n ; i++)
    {
        distance[i]=sqrt((x1-Age[i])*(x1-Age[i])+(x2-Gender[i])*(x2-Gender[i])+(x3-Polyuria[i])*(x3-Polyuria[i])+(x4-Polydipsia[i])*(x4-Polydipsia[i])+(x5-WeightLoss[i])*(x5-WeightLoss[i])+(x6-Weakness[i])*(x6-Weakness[i])+(x7-Polyphagia[i])*(x7-Polyphagia[i])+(x8-GenitalThrush[i])*(x8-GenitalThrush[i])+(x9-VisualBlurring[i])*(x9-VisualBlurring[i])+(x10-Itching[i])*(x10-Itching[i])+(x11-Irritability[i])*(x11-Irritability[i])+(x12-DelayedHealing[i])*(x12-DelayedHealing[i])+(x13-PartialParesis[i])*(x13-PartialParesis[i])+(x14-MuscleStiffness[i])*(x14-MuscleStiffness[i])+(x15-Alopecia[i])*(x15-Alopecia[i])+(x16-Obesity[i])*(x16-Obesity[i]));

        distance1[i] = distance[i];
        printf("%d ",distance1[i]);
    }

    printf("\n");

    qsort(distance, n, sizeof(int), dist);

    printf("Rank\n");
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0 ; j < n; j++)
            if(distance1[i] == distance[j] )
            {
                Rank[i] = j+1;
                printf("%d ",Rank[i]);
                break;
            }printf("\n");

    }

    KNN();

    printf("\n");

    return(0);
}
