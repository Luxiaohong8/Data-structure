import java.util.*;

public class list_test {
    public static void main(String[] args) {
        List l=new List();
        l.add(1);
        l.add(2);
        l.printList();

        l.insert(3, 1);
        l.printList();

        l.remove(4);
        l.printList();
    }
}

class List {
    private Node firstNode;
    
    public List(){
        init();
    }

    public void init() {
        firstNode=new Node(null);
    }

    //判断链表是否为空
    public boolean isEmpty(){
        if(firstNode==null) 
            return true;
        else 
            return false;
    }


    //在链表末尾插入新节点
    public void add(Object data) {
        Node node=new Node(data);

        Node pointer = firstNode;
        while (pointer.next() != null) {
            pointer = pointer.next();
        }
        pointer.setNext(node);

    }

    //插入节点
    public void insert(Object data,int i){
        Node node=new Node(data);            
        Node pointer=firstNode;
        int position=0;
        while (position<i && pointer!=null) {
            pointer=pointer.next();
            ++position;
        }

        if(pointer==null||i<0){
            System.out.println("invalid position");
            return;
        }
        node.setNext(pointer.next());
        pointer.setNext(node);
    }

    //删除节点
    public void remove(int position){
        Node pointer=firstNode;
        int i=1;
        while (i<position && pointer!=null) {
            pointer=pointer.next();
            ++i;
        }

        if(pointer==null||position<1||pointer.next()==null){
            System.out.println("invalid position");
            return;
        }

        pointer.setNext(pointer.next().next());
    }

    public void printList(){
        Node pointer=this.firstNode.next();
        while (pointer!=null) {
            System.out.print(pointer.getData()+"  ");
            pointer=pointer.next();
        }
        System.out.println();
    }

}

/**
 * Node
 */
class Node {

    private Object data;
    private Node next;

    public Node(Object data){
        this.data=data;
        this.next=null;
    }

    public Node(Object data,Node next){
        this.data=data;
        this.next=next;
    }

    public Node next(){
        return this.next;
    }

    public void setNext(Node next){
        this.next=next;
    }

    public Object getData(){
        return this.data;
    }

    public void setData(Object data){
        this.data=data;
    }

}