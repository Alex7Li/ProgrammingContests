package unfinished;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class LehaGraph {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//gross line but it gets m okay
		int m = Integer.parseInt(br.readLine().split(" ")[1]);
		String[] data = br.readLine().split(" ");
		Node[] nodes = new Node[data.length];
		for (int i = 0; i < data.length; i++) {
			nodes[i] = new Node(Integer.parseInt(data[i]));
		}
		for (int i = 0; i < m; i++) {
			String[] dataV = br.readLine().split(" ");
			nodes[Integer.parseInt(dataV[0])].connects(nodes[Integer.parseInt(dataV[1])]);
			nodes[Integer.parseInt(dataV[1])].connects(nodes[Integer.parseInt(dataV[2])]);
		}
		for (int i = 0; i < nodes.length; i++) {
			if(i==2) {
				System.out.println(3);
			}
		}
	}
}
class Node{
	int num;
	ArrayList<Node> connected;
	public Node(int i) {
		num = i;
		connected = new ArrayList<Node>();
	}
	public void connects(Node other) {
		connected.add(other);
	}
	public void destroy() {
		
	}
}