package codeforces;
import java.util.ArrayList;
import java.util.Scanner;

//http://codeforces.com/contest/902/problem/B
public class ColoringATree {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		Vertex[] v = new Vertex[n];
		for (int i = 0; i < v.length; i++) {
			v[i] = new Vertex();
		}
		for (int i = 1; i < n; i++) {
			int o = s.nextInt()-1;
			v[i].addEdge(v[o]);
			v[o].addEdge(v[i]);
		}
		v[0].setAsParent(v[0]);
		for (int i = 0; i < v.length; i++) {
			v[i].setColor(s.nextInt());
		}
		s.close();
		System.out.println(v[0].startColoring());
		
	}
	public static class Vertex{
		int goalColor;	
		int curColor = 0;
		ArrayList<Vertex> connected;
		ArrayList<Vertex> children;
		Vertex parent;
		public Vertex() {
			connected = new ArrayList<Vertex>();
			children = new ArrayList<Vertex>();
		}
		public int startColoring() {
			int count = 0;
			if(goalColor != curColor) {
				colorTree(goalColor);
				count++;
			}
			for(Vertex v:children) {
				count+=v.startColoring();
			}
			return count;
		}
		public void setColor(int c) {
			goalColor = c;
		}
		public void colorTree(int c) {
			curColor = c;
			for(Vertex v:children) {
				v.colorTree(c);
			}
		}
		public void addEdge(Vertex vertex) {
			connected.add(vertex);
		}
		public void setAsParent(Vertex parent) {
			for (Vertex v:connected) {
				if(v==parent) {
					this.parent = v;
				}else {
					children.add(v);
					v.setAsParent(this);
				}
			}
		}
		@Override
		public String toString() {
			return curColor + " " + goalColor;
		}
	}
}
