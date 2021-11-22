package misc.constructive;

import java.util.*;
//by jack
//https://naq18.kattis.com/
public class Superdoku {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] mat = new int[n][n];
        for(int i = 0; i<k; i++){
            for(int j = 0; j<n; j ++){
                mat[i][j] = sc.nextInt();
            }
        }
        boolean flag = false;
        List<Set<Integer>> rowList = new ArrayList<>();
        for(int i =0; i<k; i++){
            Set<Integer> row = new HashSet<Integer>();
            for(int j = 0; j<n; j++){
                if(!row.contains(mat[i][j])){
                    row.add(mat[i][j]);
                }else{
                    flag = true;
                }
            }
            rowList.add(row);
        }
        while(rowList.size()<n){
            rowList.add(new HashSet<Integer>());
        }
        List<Set<Integer>> colList = new ArrayList<>();
        for(int j =0; j<n; j++){
            Set<Integer> col = new HashSet<Integer>();
            for(int i = 0; i<k; i++){
                if(!col.contains(mat[i][j])){
                    col.add(mat[i][j]);
                }else{
                    flag = true;
                }
            }
            colList.add(col);
        }
        if(!flag){
            for(int j = 0; j<n; j++) {
                List<TreeSet<Integer>> possCol = new ArrayList<>();
                for (int m = k; m < n; m++) {
                    TreeSet<Integer> poss = new TreeSet<>();
                    for (int i = 1; i <= n; i++) {
                        if (!colList.get(j).contains(i) && !rowList.get(m).contains(i)) {
                            poss.add(i);
                        }
                    }
                    possCol.add(poss);
                }
                //does not work, you must fix cases where choosing the smallest
                //set first does not guarantee success like (1,5),(2,5),(1,5),
                //choosing 1,5,?.
                List<Integer> black = new ArrayList<>();
                for(int times = k; times<n; times++) {
                    int min = 0;
                    for (int i = 0; i < possCol.size(); i++) {
                        if(!black.contains(i)){
                            min = i;
                            break;
                        }
                    }
                    for (int i = 0; i < possCol.size(); i++) {
                        if (possCol.get(i).size() < possCol.get(min).size() && !black.contains(i)) {
                            min = i;
                        }
                    }
                    int fill;
                    if(possCol.get(min).size()>0) {
                        fill = possCol.get(min).first();
                    }else{
                        fill =0;
                        //throw new Error();
                    }
                    black.add(min);
                    mat[min+k][j] = fill;
                    colList.get(j).add(fill);
                    rowList.get(min+k).add(fill);
                    for (int b = 0; b < possCol.size(); b++) {
                        possCol.get(b).remove(fill);
                    }
                }
            }
            boolean flag3 = false;
            for(int p = 0; p<n; p++){
                for(int q = 0; q<n; q++){
                    if(mat[p][q] == 0) {
                        flag3 = true;
                    }
                }
            }
                System.out.println("yes");
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < n - 1; q++) {
                        System.out.print(mat[p][q] + " ");
                    }
                    System.out.println(mat[p][n - 1]);
                }
        }else{
            System.out.println("no");
        }
    }
}
