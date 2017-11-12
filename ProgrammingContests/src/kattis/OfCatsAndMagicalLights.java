package kattis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class OfCatsAndMagicalLights {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] parameters = br.readLine().split(" ");
		int nodes = Integer.parseInt(parameters[0]);
		int queries = Integer.parseInt(parameters[1]);
		String[] colors = br.readLine().split(" ");
		MagicalTree[] trees = new MagicalTree[nodes];
		for (int i = 0; i < nodes; i++) {
			trees[i] = new MagicalTree(Integer.parseInt(colors[i])-1);
		}
		String[] superTrees = br.readLine().split(" ");
		for (int i = 1; i < nodes; i++) {
			MagicalTree superTree = trees[Integer.parseInt(superTrees[i-1])-1];
			trees[i].addSuperTree(superTree);
			superTree.addSubTree(trees[i]);
		}
		for (int i = 0; i < trees.length; i++) {
			trees[i].changeColor(trees[i].color);
		}
		//trees[0].countColors();
		for (int i = 0; i < queries; i++) {
			String[] query = br.readLine().split(" ");
			int k = Integer.parseInt(query[0]);
			int x = Integer.parseInt(query[1])-1;
			if(k==0) {
				System.out.println(trees[x].magic);
			}else {
				trees[x].updateColor(k);
			}
		}
	}
}

class MagicalTree {
	int color;
	boolean hasSuperTree = false;
	MagicalTree superTree;
	ArrayList<MagicalTree> subTrees = new ArrayList<MagicalTree>();
	boolean[] magicColor = new boolean[100];
	int magic = 0;
	
	public MagicalTree(int color) {
		this.color = color;
	}
	public void setColor() {
		magic++;
		if(hasSuperTree) {
			superTree.changeColor(color);
		}
	}
	public void updateColor(int newColor) {
		changeColor(color);
		changeColor(newColor);
		color = newColor;
	}
	public void changeColor(int color) {
		if(magicColor[color]) {
			magic--;
		}else {
			magic++;
		}
		magicColor[color] = !magicColor[color];
		if(hasSuperTree) {
			superTree.changeColor(color);
		}
	}
//	public void countColors() {
//		magicColor[color] = !magicColor[color];
//		for (int i = 0; i < subTrees.size(); i++) {
//			subTrees.get(i).countColors();
//			for (int j = 0; j < magicColor.length; j++) {
//				magicColor[j]=magicColor[j]^subTrees.get(i).magicColor[j];
//			}
//		}
//		for (int i = 0; i < magicColor.length; i++) {
//			if(magicColor[i]) {
//				magic++;
//			}
//		}
//	}
	
	public void addSubTree(MagicalTree subTree) {
		subTrees.add(subTree);
	}
	
	public void addSuperTree(MagicalTree superT) {
		superTree = superT;
		hasSuperTree = true;
	}
}
