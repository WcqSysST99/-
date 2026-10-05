/*
顺序存储
n层，完全二叉树，节点数？最大2^n-1 最小 2^(n-1)+1
tree[2^n]
连接存储：

new delete
left = NULL;
right = NULL;
先根遍历：
先到根节点，再到左子树，再到右子树
中根遍历：
先左，再根，最后右
后根遍历：
先左再右，最后根
*/
struct node{
	int data;
	node* left;
	node* right;
	node* parent; //指向父节点，三叉链表
};
//先根
using namespace std;
#include<bits/stdc++.h>
void Preorder(node* root){
	if(root == NULL) return;
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
	
}
void Midorder(node* root){
	if(root == NULL) return;
	Preorder(root->left);
	printf("%d ",root->data);
	Preorder(root->right);
	
}
void Behindorder(node* root){
	if(root == NULL) return;
	Preorder(root->left);
	Preorder(root->right);
	printf("%d ",root->data);
}
//要使一颗非空二叉树的先根序列和中根序列相同，非叶节点必须满足：
//A.只有左子树 √B.只有右子树 C.节点的度为1 D.节点的度均为2

// 层次遍历 广度优先搜索 BFS 队列
//用一个队列，先把根节点入队，反复执行以下操作直到队列为空：
/*
1. 出队一个节点并访问
2. 若有左孩子，把左孩子入队
3. 若有右孩子，把右孩子入队

*/
void level(node* root){
	queue<node*> Q;
	if(root!=NULL) Q.push(root);
	while(!Q.empty()){
		node* p = Q.front();
		Q.pop();
		if(p->left != NULL) Q.push(p->left);
		if(p->right != NULL) Q.push(p->right);
	}
}
//搜索符合数据条件的节点
node* Search(node* root,int target){
	if(root == NULL) return NULL;
	if(root->data == target) return root;
	node* ans = Search(root->left,target);
	if(ans != NULL) return ans;
	return Search(root->right,target);
}
//搜索给定节点的父节点
node* findfather(node* root,node* p){
	if(root == NULL || p == root) return NULL;
	if(root->left == p|| root -> right == p) return root;
	node* ans = findfather(root->left,p);
	if(ans != NULL) return ans;
	return findfather(root->right,p);
}
//计算结点个数
int Count(node* root){
	if(root == NULL) return 0;
	return Count(root->left) + Count(root->right);
}
//计算二叉树高度
int depth(node* root){
	if(root == NULL) return -1;
	int d_1 = depth(root->left);
	int d_2 = depth(root->right);
	return (d_1 > d_2) ? d_1 + 1 : d_2 + 1;
	//if(d_1 > d_2) return d_1 + 1;
	//else return d_2 + 1;
}
//删树
void Del(node* &root){
	if(root == NULL) return;
	Del(root->left);
	Del(root->right);
	delete root;
	root = NULL;
	}




