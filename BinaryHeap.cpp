#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
}

void insert_in_heap()
{
  heapsize++;
  binaryheap[heapsize].flag=flagval;
  binaryheap[heapsize].dist=distance;

  int parent=heapsize/2,child=heapsize;
  while(binaryheap[child].dist<binaryheap[parent].dist && parent>=1 && child>1)
  {
      swap(&binaryheap[child].dist,&binaryheap[parent].dist);
      swap(&binaryheap[child].flag,&binaryheap[parent].flag);
      child=parent;
      parent=child/2;
  }
}


void main()
{

     int n;
     scanf("%d",&n);
     heapsize=0;

     int cnt=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&flagval);
        scanf("%d",&distance);
        insert_in_heap();
    }

    int majority_flag=0;

     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     delete_top_element();

     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     delete_top_element();
     binaryheap[1].flag==1?majority_flag++:majority_flag--;

     majority_flag>0?printf("\nMajority_Flag_Value=%d\n",1):printf("\nMajority_Flag_Value=%d\n",0);

     return 0;
}
