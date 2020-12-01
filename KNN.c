#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//62 0 1 1 0 1 1 0 1 0 1 0 1 1 0 0

int x;

struct binheap
{
  int flag;
  int dist;
};

int heapsize,current_node,left_child,right_child,small,flagval,distance;

struct binheap binaryheap[1000];

int swap(int *a,int *b){ int temp=*a; *a=*b; *b=temp;}

int Reform_Required()
{
    (left_child<=heapsize && binaryheap[left_child].dist<binaryheap[current_node].dist) ? small=left_child:small;
    if(right_child<=heapsize && binaryheap[right_child].dist<binaryheap[current_node].dist)
    {
        if(small!=1e9){if(binaryheap[right_child].dist<binaryheap[small].dist)small=right_child;}
        else if(small==1e9)small=right_child;
    }
    int res=(small==1e9)?0:1;
    return res;

}
int reform_binaryheap()
{
  swap(&binaryheap[small].dist,&binaryheap[current_node].dist);
  swap(&binaryheap[small].flag,&binaryheap[current_node].flag);
  current_node=small;
}

int delete_top_element()
{

      binaryheap[1].dist=binaryheap[heapsize].dist;
      binaryheap[1].flag=binaryheap[heapsize].flag;
      heapsize--;
      current_node=1;
      for(;;)
      {
          left_child=2*current_node;
          right_child=(2*current_node)+1;
          small=1e9;
          int ret=Reform_Required();
          if(ret==0)break;
          reform_binaryheap();
      }

      printf("%d %d\n", binaryheap[1].dist,binaryheap[1].flag);
}

void insert_in_heap(int a, int b)
{
  //printf("%d %d Function call\n",a,b);
  heapsize++;
  binaryheap[heapsize].flag=b;
  binaryheap[heapsize].dist=a;

  int parent=heapsize/2, child=heapsize;
  while(binaryheap[child].dist<binaryheap[parent].dist && parent>=1 && child>1)
  {
      swap(&binaryheap[child].dist,&binaryheap[parent].dist);
      swap(&binaryheap[child].flag,&binaryheap[parent].flag);
      child=parent;
      parent=child/2;
  }
}

int r = 500, c = 17;


//int Age[1000],Gender[1000],Polyuria[1000],Polydipsia[1000],WeightLoss[1000],Weakness[1000],Polyphagia[1000],GenitalThrush[1000],VisualBlurring[1000],Itching[1000],Irritability[1000],DelayedHealing[1000],PartialParesis[1000],MuscleStiffness[1000],Alopecia[1000],Obesity[1000],Classification[1000];
//int distance1[1000];

void KNN()
{
}


int main()
{
    printf("Age Gender Polyuria Polydipsia Sudden_Weight_loss Weakness Polyphagia Genital_thrush Visual_blurring Itching Irritability Delayed_healing Partial_paresis Muscle_stiffness Alopecia Obesity\n");

    int *dataset = (int *)malloc(r * c * sizeof(int));

    int *testarr = (int*)malloc(c * sizeof(int));

    for (int i = 0; i < c-1; i++)
        {
            scanf("%d",&testarr[i]);
        }

    freopen("training.txt","r",stdin);

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",(dataset + i*c + j));

    int Distance = 0, flag = 0, dist = 0;

    heapsize=0;
    int cnt=0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c-1; j++)
            {
                dist = (*(dataset + i*c + j) - testarr[j]);

                dist *= dist;

                Distance += dist;
            }

            Distance = sqrt(Distance);
         flag = *(dataset + i*c + 16);

         //printf("%d %d\n", Distance,flag);

         insert_in_heap(Distance, flag);

         Distance = 0;
    }

    for(int i=0;i<heapsize;i++)
    {
     printf("%d %d\n",  binaryheap[i].flag,  binaryheap[i].dist);
    }


     printf("Nearest 3 neighbors\n");

     int majority_flag=0;

     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     printf("%d %d\n", binaryheap[1].dist,binaryheap[1].flag);

     delete_top_element();

     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     delete_top_element();
     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     printf("%d\n",majority_flag);

     majority_flag>0?printf("The patient may have diabetes"):printf("The patient may NOT have diabetes");

    return 0;
}
