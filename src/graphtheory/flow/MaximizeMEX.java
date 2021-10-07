package graphtheory.flow;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// http://codeforces.com/contest/1139/problem/E
// this was hard
public class MaximizeMEX {

    private static List<Student>[] wPot;
    private static List<Student>[] clubMembers;
    private static int[] potOfClubRep;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            students[i] = new Student();
        }
        for (int i = 0; i < n; i++) {
            students[i].pot = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            students[i].club = sc.nextInt() - 1;
        }
        // wPot[i] = list of students with potential i
        wPot = new ArrayList[5001];
        clubMembers = new ArrayList[m];
        for (int i = 0; i < wPot.length; i++) {
            wPot[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            clubMembers[i] = new ArrayList<>();
        }
        for (Student s : students) {
            wPot[s.pot].add(s);
            clubMembers[s.club].add(s);
        }
        // if this club is used, and if so, which potential it's used on
        potOfClubRep = new int[m];
        Arrays.fill(potOfClubRep, -1);

        boolean possible = true;
        int depth = -1;
        while (possible) {
            depth++;
            possible = addRow(depth, new boolean[m], new boolean[depth + 1]);
        }
        int d = sc.nextInt();
        for (int i = 0; i < d; i++) {
            int indToRemove = sc.nextInt() - 1;
            int remPotential = students[indToRemove].pot;
            int club = students[indToRemove].club;
            boolean a = wPot[remPotential].remove(students[indToRemove]);
            boolean b = clubMembers[students[indToRemove].club].remove((students[indToRemove]));
            if (!a || !b) {
                throw new RuntimeException();
            }
            if (potOfClubRep[club] == remPotential) {
                potOfClubRep[club] = -1;
                while (depth > remPotential && !addRow(remPotential, new boolean[m], new boolean[depth + 1])) {
                    depth--;
                    for (int j = 0; j < potOfClubRep.length; j++) {
                        if (potOfClubRep[j] == depth) {
                            potOfClubRep[j] = -1;
                            break;
                        }
                    }
                }
            }
            System.out.println(depth);
        }
    }

    private static boolean addRow(int depth, boolean[] seenClub, boolean[] seenDepth) {
        if (seenDepth[depth]) {
            return false;
        }
        seenDepth[depth] = true;
        for (Student s : wPot[depth]) {
            if (!seenClub[s.club]) {
                seenClub[s.club] = true;
                if (potOfClubRep[s.club] == -1) {
                    potOfClubRep[s.club] = s.pot;
                    return true;
                }
                for (Student s2 : clubMembers[s.club]) {
                    if (s.pot != s2.pot && s2.pot < seenDepth.length &&
                            (potOfClubRep[s.club] == -1 || potOfClubRep[s.club] == s2.pot) &&
                            addRow(s2.pot, seenClub, seenDepth)) {
                        potOfClubRep[s.club] = depth;
                        return true;
                    }

                }
            }
        }
        return false;
    }

    private static class Student {
        int pot;
        int club;
    }
}
