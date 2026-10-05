#include<bits/stdc++.h>
using namespace std;
//线索二叉树
//需要高频查找节点的前驱和后继 原来的二叉树只能通过递归和回溯来查找对应节点的前驱和后继
//前驱、后继分为先根、中根、后根
struct Treenode{
	Treenode* left;
	Treenode* right;
	int data;
	bool Lthread; //这个节点的left指向的是前驱 还是 左孩子 if Lthread == 0 指的是左孩子 反之为前驱
	bool Rthread; //这个节点的right指向的是 后继 还是 右孩子 if Rthread == 0 指的是右孩子 反之为后继
	//按   中/先/后遍历顺序生成的线索二叉树 分别称为 中/先/后 线索二叉树
};
Treenode* pre = NULL;
//建立普通二叉树 先根补空读入
void Build_Tree(Treenode* &root){
	char c; cin>>c;
	if(c == '#') root = NULL;
	else{
		root = new Treenode;
		root->data = c;
		root->Lthread = root->Rthread = 0;
		Build_Tree(root->left);
		Build_Tree(root->right);
	}
}
void Create_Tree(Treenode* root){
	pre = NULL;
	if(root != NULL){
		Inthread(root);
		if(pre->rchild == NULL) pre->Rthread = 1;
	}
}
//线索化能很快的找到前驱、后继节点。好查
//为什么不能全用线索化呢？线索二叉树删节点、改节点的复杂度极高
//适用场景？要高频查找大二叉树的前驱、后继节点的时候，且删改操作较少。

//线索化
void InThread(Treenode* &root){
	if(root == NULL) return;
	
	InThread(root->left);
	
	if(root->left == NULL){
		root->left = pre;
		root->Lthread = 1;
	}
	if(pre != NULL and pre->right ==NULL){
		pre->right = root;
		pre->Rthread = 1;
	}
	pre = root;
	InThread(root->right);
}

