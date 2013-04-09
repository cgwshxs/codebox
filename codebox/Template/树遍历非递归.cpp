void PreOrderUnrec(Bitree p){
	if(p==NULL)
		return;
	Stack s;
	while (p!=null || !StackEmpty(s)){
		while (p!=null){           //����������
			visite(p->data);
			push(s,p);
			p=p->lchild;       
		}//endwhile
		if (!StackEmpty(s)){         //ͨ����һ��ѭ���е���Ƕwhileʵ������������
			p=pop(s);
			p=p->rchild;        
		}//endif
	}//endwhile 
}//PreOrderUnrec
2.��������ǵݹ��㷨
void InOrderUnrec(Bitree p){
	if(p==NULL)
		return;
	Stack s;
	while (p!=null || !StackEmpty(s)){
		while (p!=null){           //����������
			push(s,p);
			p=p->lchild;
		}//endwhile
		if (!StackEmpty(s)){
			p=pop(s);
			visite(p->data);        //���ʸ����
			p=p->rchild;            //ͨ����һ��ѭ��ʵ������������
		}//endif   
	}//endwhile
}//InOrderUnrec
3.��������ǵݹ��㷨
#define maxsize 100
typedef enum{L,R} tagtype;
typedef struct{
	Bitree p;
	tagtype tag;
}stacknode;
void PostOrderUnrec(Bitree p){
	if(p==NULL)
		return;
	Stack s;
	do {
		while (p!=null){        //����������
			x.ptr = p; 
			x.tag = L;         //���Ϊ������
			push(s,x);
			p=p->lchild;
		}
		while (!StackEmpty(s) && s.Elem[s.top].tag==R){
			x = pop(s);
			p = x.ptr;
			visite(p->data);   //tagΪR����ʾ������������ϣ��ʷ��ʸ����       
		}
		if (!StackEmpty(s)){
			s.Elem[s.top].tag =R;     //����������
			p=s.Elem[s.top].ptr->rchild;        
		}    
	}while (!StackEmpty(s));
}//PostOrderUnrec
//ԭʼ
void midsearch(node *root){
	if(root==NULL)
		return ;
	stack<node*> st;
	st.push(root);
	while(st.size()>0){
		while(root->left!=NULL){
			st.push(root->left);
			root=root->left;
		}
		while(st.size()>0){
			root=st.top();
			st.pop();
			cout<<root->m<<" ";
			if(root->right!=NULL){
				root=root->right;
				st.push(root);
				break;
			}
		}
	}
}

