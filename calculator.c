#include <stdio.h>
#include <stdlib.h>



int main(){
	
	int **arr = NULL, **brr = NULL, **crr = NULL;
    
    int choice;
    double a=0,b=0,c=0,d=0,num=0;
    double result=0;
    int i1,j1,i2,j2,i,j,m,n;
    int que=0;
    int deter=0;
    
    
    printf("1.加法\n2.减法\n3.乘法\n4.除法\n5.矩阵加法\n6.矩阵减法\n7.矩阵数乘\n8.矩阵乘积\n9.矩阵转置\n"
	"请选择运算类型前所代表的数字：");
	
	scanf("%d",&choice);
	
	
	//part one: 输入要求 
	if(choice>=1&&choice<=4){
		printf("请输入你要的数字，并且每输入一个数字，按下空格回车或tab，如果结束输入，请输入0：\n");
	} 
	
	
	//part two: 运算部分
	switch (choice){
		case 1:
			do{
				scanf("%lf",&a);
				result+=a;
			}while(a!=0);
			que=1;
			break;
			//加法完毕 
		case 2:
			scanf("%lf",&a);
			result=a;
			while(a!=0){
				scanf("%lf",&a);
				if(a==0){
					break;
				}
				result-=a;
			}
			que=1;
			break;
			//减法完毕 
        case 3:
        	scanf("%lf",&d);
			result=d;
			do{
				scanf("%lf",&a);
				if(a==0){
					break;
				}
				result*=a; 
			}while(a!=0);
			que=1;
			break;
			//乘法完毕 
		case 4:
			scanf("%lf",&d);
			result=d;
			do{
				scanf("%lf",&a);
				if(a==0){
					break;
				}
				result/=a; 
			}while(a!=0);
			que=1;
			break;
			//除法完毕
//开始矩阵运算 
	    case 5: {
		        printf("请输入你需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
		        scanf("%d %d",&i1,&j1);
		        
				// 1. 先分配行指针
				arr = (int **)malloc(i1 * sizeof(int *));
				brr = (int **)malloc(i1 * sizeof(int *));
				crr = (int **)malloc(i1 * sizeof(int *));
				
				// 2. 再为每一行分配列空间
				for (i = 0; i < i1; i++) {
				    arr[i] = (int *)malloc(j1 * sizeof(int));
				    brr[i] = (int *)malloc(j1 * sizeof(int));
				    crr[i] = (int *)malloc(j1 * sizeof(int));
	            }
		        
		        printf("请输入对应第一个矩阵，每个元用空格隔开：\n");
				 
		        for(i=0;i<i1;i++){
		        	for(j=0;j<j1;j++){
		        		scanf("%d",&arr[i][j]);
					}
				}
		        
		        printf("请输入对应第二个矩阵，每个元用空格隔开：\n");
		        
		        for(i=0;i<i1;i++){
		        	for(j=0;j<j1;j++){
		        		scanf("%d",&brr[i][j]);
					}
				}
			
				for(i=0;i<i1;i++){
					for(j=0;j<j1;j++){
						crr[i][j]=arr[i][j]+brr[i][j];
					}
				}
	        
		        que=2;
		        break;
			}
	        //矩阵加法结束
		case 6: {
			
	        printf("请输入你需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
	        scanf("%d %d",&i1,&j1);
	        
	        // 1. 先分配行指针
			arr = (int **)malloc(i1 * sizeof(int *));
			brr = (int **)malloc(i1 * sizeof(int *));
			crr = (int **)malloc(i1 * sizeof(int *));
			
			// 2. 再为每一行分配列空间
			for (i = 0; i < i1; i++) {
			    arr[i] = (int *)malloc(j1 * sizeof(int));
			    brr[i] = (int *)malloc(j1 * sizeof(int));
			    crr[i] = (int *)malloc(j1 * sizeof(int));
			}
	        
	        printf("请输入对应第一个矩阵，每个元用空格隔开：\n");
			 
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j1;j++){
	        		scanf("%d",&arr[i][j]);
				}
			}
	        
	        printf("请输入对应第二个矩阵，每个元用空格隔开：\n");
	        
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j1;j++){
	        		scanf("%d",&brr[i][j]);
				}
			}
			
			for(i=0;i<i1;i++){
				for(j=0;j<j1;j++){
					crr[i][j]=arr[i][j]-brr[i][j];
				}
			}
	        
	        que=2;
	        
	        break;
	        
	    }
	        //矩阵减法结束 
	        
	    case 7:{
			
	    	printf("请输入你需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
	        scanf("%d %d",&i1,&j1);
	        
	        arr=(int**)malloc(i1*sizeof(int*));
	        crr=(int**)malloc(i1*sizeof(int*));
	        
	        for (i = 0; i < i1; i++) {
			    arr[i] = (int *)malloc(j1 * sizeof(int));
			    crr[i] = (int *)malloc(j1 * sizeof(int));
			}
	    	
	    	printf("请输入对应矩阵，每个元用空格隔开：\n");
			 
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j1;j++){
	        		scanf("%d",&arr[i][j]);
				}
			}
			
			printf("请输入需要数乘的一个数："); 
			scanf("%lf",&num);
	    	
	    	
	    	for(i=0;i<i1;i++){
	    		for(j=0;j<j1;j++){
	    			crr[i][j]=num*arr[i][j];
				}
			}
	    	que=2;
	    	break;
	    	
	    }
	    	
	    	
	    case 8:{
		
	    	do{
		    	printf("请输入你第一个需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
		        scanf("%d %d",&i1,&j1);
		        
		        printf("请输入你第二个需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
		        scanf("%d %d",&i2,&j2);
		        
		        if(j1!=i2){
		        	printf("矩阵乘法要求第一矩阵之行数 = 第二矩阵之列数，\n" 
					"您的输入不符合要求，请重新输入预设数字") ;
				}
	        }while(j1!=i2);
	        //输入并且判断是否符合矩阵乘法要求
			
	        arr=(int**)malloc(i1*sizeof(int*));
	        brr=(int**)malloc(i2*sizeof(int*));
	        crr=(int**)malloc(i1*sizeof(int*));
	        
			for(i=0;i<i2;i++){
				brr[i] = (int *)malloc(j2 * sizeof(int));
			}
	        for (i = 0; i < i1; i++) {
			    arr[i] = (int *)malloc(j1 * sizeof(int));
			    crr[i] = (int *)malloc(j2 * sizeof(int));
			}
			
	        
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j2;j++){
	        		crr[i][j]=0;
				}
			}
	        //初始化crr 
	        
	        
	        printf("预设通过了（厉害哦）。\n"
			"请输入对应第一个矩阵，每个元用空格隔开：\n");
			 
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j1;j++){
	        		scanf("%d",&arr[i][j]);
				}
			}
			
			
	        printf("第一个输入完毕\n请输入对应第二个矩阵，每个元用空格隔开：\n");
	        
	        for(i=0;i<i2;i++){
	        	for(j=0;j<j2;j++){
	        		scanf("%d",&brr[i][j]);
				}
			}
			
			//开始计算
			
		   /*先算a的那一行乘上b的那一列,m是行数，n是列数 
		   */ 
			
			printf("开始计算了\n");
			
			for(m = 0; m < i1; m++){
			    for(n = 0; n < j2; n++){
			        crr[m][n] = 0;
			        for(j = 0; j < j1; j++){ // 注意这里是用 j1，且只有三层
			            crr[m][n] += arr[m][j] * brr[j][n];
			        }
			    }
			}
			
			printf("计算完毕\n");
	        que=2;
	        break;
	        
	    }
	        //矩阵乘法完毕 
	    case 9:{
			
	    	printf("请输入你需要运算的矩阵规格,分别对应行和列，中间请用空格隔开\n");
	        scanf("%d %d",&i1,&j1);
	        
	        arr=(int**)malloc(i1*sizeof(int*));
	        crr=(int**)malloc(j1*sizeof(int*));
	        
			for (i = 0; i < i1; i++) {
			    arr[i] = (int *)malloc(j1 * sizeof(int));
			}

	         for (i = 0; i < j1; i++) {
			    crr[i] = (int *)malloc(i1 * sizeof(int));
			}
	        
	        printf("请输入对应矩阵，每个元用空格隔开：\n");
			 
	        for(i=0;i<i1;i++){
	        	for(j=0;j<j1;j++){
	        		scanf("%d",&arr[i][j]);
				}
			}
        	//开始运算
			
			for(i=0;i<i1;i++){
				for(j=0;j<j1;j++){
					crr[j][i]=arr[i][j];
				}
			} 
			que=2;
			break; 
			
		}
			//数组转置结束
			 
	}
	
	//开始结果输出
	 
	printf("运算结果为\n") ;
	
	if(que==1){
		printf("%lf",result);
	} else 
	if(que==2){
		if(choice<=7&&choice>=5){
			for(i=0;i<i1;i++){
				for(j=0;j<j1;j++){
					deter++;
					printf("%d ",crr[i][j]);
					if(deter%j1==0){
						printf("\n");
					}
				}
			}
		}else
		if(choice==8){
			deter=0;
			for(i=0;i<i1;i++){
				for(j=0;j<j2;j++){
					printf("%d ",crr[i][j]);
					deter++;
					if(deter%j2==0){
						printf("\n");
					}
				}
			}
		}else
		if(choice==9){
			deter=0;
			for(i=0;i<j1;i++){
				for(j=0;j<i1;j++){
					printf("%d ",crr[i][j]);
					deter++;
					if(deter%i1==0){
						printf("\n");
				}
			}
		}
	}
}
	
//结束 
	
	// 结束前释放内存 (根据不同的 choice 释放不同的大小，简单起见可以全释放)
	if (arr) {
	    for (i = 0; i < i1; i++) free(arr[i]);
	    free(arr);
	}
	if (brr) {
	    for (i = 0; i < (choice == 8 ? i2 : i1); i++) free(brr[i]);
	    free(brr);
	}
	if (crr) {
	    if (choice == 9) {
	        for (i = 0; i < j1; i++) free(crr[i]);
	    } else {
	        for (i = 0; i < i1; i++) free(crr[i]);
	    }
	    free(crr);
	}
	
	return 0;
	
}