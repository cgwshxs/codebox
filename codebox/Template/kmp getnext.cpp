 ////char ss[]="abaabcaba";
     //        -100112012         
//char ss[]="abaabcabaabda";
 //         -1001120123450
//char ss[]="abaabcac";
 //         -10011201
//char ss[]="aaaab";
 //         -10123   
void get_next(){
  int n=strlen(ss);
  num[0]=-1;
  num[1]=0;
  int j=0;
  for(int i=2;i<=n;i++){
    while(j>0&&ss[i-1]!=ss[j])//Ѱ��ǰһ���ַ�����Ⱥ�׺��
      j=num[j];
    if(ss[i-1]==ss[j]){//�ҵ���,��1��ʾ[ǰһ���ַ���ȣ���һ���ַ����ɵڶ��αȽϷ�ʽ]
      j++;
    }//else ��������0
 num[i]=j;
  }
}