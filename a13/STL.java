import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

public class STL {
    public static void main(String args[]) throws Exception
    {
        Scanner in=new Scanner(System.in);
        int choice;

        PriorityQueue<Integer> q1=new PriorityQueue<>();
        Stack<Integer> s1=new Stack<>();
        LinkedList<Integer> l1=new LinkedList<>();
        ArrayList<Integer> arrayList=new ArrayList<>();
        HashMap<String,Integer> hs=new HashMap<>();
        do {
            System.out.println("Enter choice");
            System.out.println("\t1.Queue\n\t2.Stack\n\t3.LinkedList\n\t4.Arraylist\n\t5.HashMap\n\t6.Exit");
            choice=in.nextInt();
            switch(choice)
            {
                case 1:
                    System.out.println("------Priority Queue------");
                    System.out.println("1.Enqueue\t2Dequeue\t3.Exit");
                    choice=in.nextInt();
                    switch (choice)
                    {
                        case 1:
                            System.out.println("Enter Number:");
                            q1.add(new Integer(in.nextInt()));
                            System.out.println("Added :"+q1.peek());
                            break;
                        case 2:
                            System.out.println("Removed Element: "+q1.remove());
                            break;
                        case 3:break;
                    }
                    break;
                case 2:
                    System.out.println("------Stack------");
                    System.out.println("1.Push\t2.Pop\t3.Top\t4.Exit");
                    choice=in.nextInt();
                    switch(choice)
                    {
                        case 1:
                            System.out.println("Enter Number:");
                            s1.push(new Integer(in.nextInt()));
                            break;
                        case 2:
                            System.out.println("Popped Element :"+s1.pop());
                            break;
                        case 3:
                            System.out.println("Stack top:"+s1.peek());
                            break;
                        case 4:break;
                    }
                    break;
                case 3:
                    System.out.println("------LinkedList------\n1.Add\t2.Remove\t3.First\t4.Last");
                    choice=in.nextInt();
                    switch (choice)
                    {
                        case 1:
                            System.out.println("Enter Number:");
                            l1.add(new Integer(in.nextInt()));
                            break;
                        case 2:
                            System.out.println("Enter element to be deleted:");
                            System.out.println("Removed Element:"+l1.remove(in.nextInt()));
                            break;
                        case 3:
                            System.out.println("First Element:"+l1.getFirst());
                            break;
                        case 4:
                            System.out.println("Last Element:"+l1.getLast());
                            break;
                    }
                    break;
                case 4:
                    System.out.println("------ArrayList------");
                    arrayList.add(5);
                    arrayList.add(10);
                    System.out.println("Removed Element at index 0 :"+arrayList.remove(0));
                    System.out.println("Size of arraylist:"+arrayList.size());
                    break;
                case 5:
                    System.out.println("------HashMap-------");
                    System.out.println("Enter key:");
                    in.next();
                    String key=in.nextLine();
                    System.out.println("Enter Value");
                    int value=in.nextInt();
                    hs.put(key,value);
                    System.out.println("Record Inserted");
                    hs.put("Game",123);
                    System.out.println("Removed element(Game):"+hs.remove("Game"));
                    System.out.println("Size:"+hs.size());
                    System.out.println("Hashcode Value for this map:"+hs.hashCode());
                    break;
            }
        }while(choice!=6);
    }
}
