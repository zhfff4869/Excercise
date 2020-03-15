class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
//注意输入的虽然是结点,但其作为子树的根节点是代表着一颗树的
public class Subtree {//判断tree2是不是tree1的子结构
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if(root1 == null||root2 == null) return false;
        boolean result = false;
        if(root1.val==root2.val){
            result=judge(root1,root2);  //对应起来后进行判断
        }
        if(!result){
            result=HasSubtree(root1.left,root2);    //先把root2根节点与tree1中的位置对应起来
        }
        if(!result){
            result=HasSubtree(root1.right,root2);
        }
        return result;
        
    }
    public static boolean judge(TreeNode node1, TreeNode node2) {
        //如果Tree2已经遍历完了都能对应的上，返回true
        if (node2 == null) {    //要先判断node2,再判断node1,避免同时为null时出错
            return true;
        }
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if (node1 == null) {
            return false;
        }
        //如果其中有一个点没有对应上，返回false
        if (node1.val != node2.val) {  
                return false;
        }
         
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return judge(node1.left,node2.left) && judge(node1.right,node2.right);
    }
}
