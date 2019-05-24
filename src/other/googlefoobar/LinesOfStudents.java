package other.googlefoobar;

//https://codingworksample.io/c/feedback/AVDQWG-F4F
public class LinesOfStudents {
    public int solution(int[] A) {
        boolean[] seen = new boolean[A.length];
        int rows = 0;
        boolean done = false;

        // Greedily pick each row, it can be shown to be optimal
        while(!done){
            int lastSize = Integer.MAX_VALUE;
            for (int i = 0; i < A.length; i++) {
                if(!seen[i] && A[i]<lastSize){
                    seen[i] = true;
                    lastSize = A[i];
                }
            }
            if(lastSize==Integer.MAX_VALUE){
                done = true;
            }else{
                rows++;
            }
        }
        return rows;
    }

    public static void main(String[] args) {
        int[] tcase = {5,3,4,2,1};
        LinesOfStudents s = new LinesOfStudents();
        System.out.println(s.solution(tcase));
    }
}

