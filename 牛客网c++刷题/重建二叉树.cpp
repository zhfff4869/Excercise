#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty())
		{
			return NULL;
		}
		TreeNode* p = new TreeNode(pre[0]);	//前序序列第一个数为根结点
		if (pre.size() == 1)
		{
			return p;
		}

		int root = pre[0];
		int flag;
		vector<int> left_pre, right_pre, left_vin, right_vin;


		//pre.erase(pre.begin() + 0);

		for (int i = 0; i < vin.size(); i++)	//根节点的中序序列下标储存到flag里，注意，i是有符号int，size是无符号，所以会有警告
		{
			if (vin[i] == root)
			{
				flag = i;
				break;
			}
		}

		for (int i = 0; i < flag; i++)		//更新左右中序序列
			left_vin.push_back(vin[i]);
		for (int i = flag + 1; i < vin.size(); i++)
			right_vin.push_back(vin[i]);
		for (int i = 1; i < flag+1; i++)	//更新左右前序序列
			left_pre.push_back(pre[i]);
		for (int i = flag + 1; i < pre.size(); i++)
			right_pre.push_back(pre[i]);

		p->left = reConstructBinaryTree(left_pre, left_vin);	//更新根节点的左孩子，迭代
		p->right = reConstructBinaryTree(right_pre, right_vin);	//更新根节点的右孩子，迭代
		return p;	//返回根节点：这里必须加上，因为不管size为1或是大于1，都已经创建了根节点，区别只是大于1时要赋值left和right
	}

	void preOrder(TreeNode* &T)
	{
		if (T == NULL) return;
		else
		{
			cout << T->val << "  ";
			preOrder(T->left);
			preOrder(T->right);
		}
	}
};

int main()
{
	system("color f0");
	system("title 重建二叉树");
	Solution S;
	vector<int> pre({ 1,2,4,7,3,5,6,8 });
	vector<int> vin({ 4,7,2,1,5,3,8,6 });
	TreeNode* p = S.reConstructBinaryTree(pre, vin);
	cout << "创建二叉树成功!" << endl;
	cout << "前序遍历二叉树:" << endl;
	S.preOrder(p);
	system("pause");
	return 0;
}
