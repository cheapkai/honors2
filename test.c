#include<stdio.h>
#include<mpi.h>

int main (int argc, char **argv)
{
int numprocs;
int myid;
int i;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
MPI_Comm_rank(MPI_COMM_WORLD, &myid);
int tp[1];tp[0]=0;int tpr[1];int tpr2[1];
int tp1[1];tp1[0]=0;
//MPI_Status stat;
int start = 0;


for(start=0;start<5;start++)
{


if(myid == 0)
{
printf("PING!\n->\n->\n->\n");
	MPI_Send(tp,1,MPI_INT,1,123,MPI_COMM_WORLD);
MPI_Recv(tpr,1,MPI_INT,1,122,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
}
else
{
MPI_Recv(tpr2,1,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("               PONG\n         <-\n     -<   \n");
MPI_Send(tp1,1,MPI_INT,0,122,MPI_COMM_WORLD);
}

//MPI_Waitall();
//MPI_Finalize();
}
MPI_Finalize();
return 0;
}
