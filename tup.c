#include <mpi.h>
#include <stdio.h>

int main (int argc, char **argv)
{
int tos[1000];
int onr[1000];
int buf[1000];
int numprocs;
int myid;
int i;

MPI_Status stat;
int tp;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
MPI_Comm_rank(MPI_COMM_WORLD, &myid);

if(myid == 0)
{
int x;scanf("%d",&x);
for(i=0;i<x;i++)scanf("%d",&tos[i]);
tp = x;
MPI_Scatter(tos,2,MPI_INT,buf,2,MPI_INT,0,MPI_COMM_WORLD);
}


else{
MPI_Scatter(NULL,0,MPI_INT,buf,2,MPI_INT,0,MPI_COMM_WORLD);

}




printf("%d %d %d\n",myid,buf[0],buf[1]);


//do sorting 
if(myid == 0)
{
MPI_Gather(buf,2,MPI_INT,onr,2,MPI_INT,0,MPI_COMM_WORLD);

int y=0;
for(y=0;y<tp;y++)printf("%d\n",tos[y]);


}

else
{
MPI_Gather(buf,2,MPI_INT,NULL,2,MPI_INT,0,MPI_COMM_WORLD);
}



MPI_Finalize();

}
