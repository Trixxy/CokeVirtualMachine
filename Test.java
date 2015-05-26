import java.util.ArrayList;

public class Test {
	private int var1 = 2;
	private final int var2 = 3;
	private ArrayList<Integer> al;

	public void foo1(){
		al = new ArrayList<Integer>();
	}

	public void foo2(){
		al.add(1);
	}

	public void foo3(int test){
		if(1 < test){
		}
	}

	public static void main(String [] args){
		System.out.println("Test");
	}

}
