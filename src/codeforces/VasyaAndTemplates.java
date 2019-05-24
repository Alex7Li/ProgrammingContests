package codeforces;

import java.io.*;
import java.util.*;

//https://codeforces.com/contest/1086/problem/C
public class VasyaAndTemplates {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int cases = Integer.parseInt(br.readLine());
        for (int t = 0; t < cases; t++) {
            char maxLetter = (char) (Integer.parseInt(br.readLine()) + 'a');
            char[] s = br.readLine().toCharArray();
            char[] a = br.readLine().toCharArray();
            char[] b = br.readLine().toCharArray();
            Map<Character, Character> template = new HashMap<>();
            SortedSet<Character> valuesUnmapped = new TreeSet<>();
            for (char i = 'a'; i < maxLetter; i++) {
                valuesUnmapped.add(i);
            }
            boolean possible = true;
            for (int i = 0; i < a.length; i++) {
                if (a[i] == b[i]) {
                    if (template.containsKey(s[i])) {
                        if (template.get(s[i]) != a[i]) {
                            possible = false;
                            break;
                        }
                    } else if (valuesUnmapped.contains(a[i])) {
                        template.put(s[i], a[i]);
                        valuesUnmapped.remove(a[i]);
                    } else {
                        possible = false;
                        break;
                    }
                } else {
                    if (template.containsKey(s[i])) {
                        if (template.get(s[i]) > a[i] && template.get(s[i]) < b[i]) {
                            possible = true;
                        } else if (template.get(s[i]) == a[i]) {
                            possible = greaterThanAssignment(i, s, a, template, valuesUnmapped);
                        } else if (template.get(s[i]) == b[i]) {
                            possible = lessThanAssignment(i, s, b, template, valuesUnmapped);
                        } else {
                            possible = false;
                        }
                    } else {
                        possible = false;
                        SortedSet<Character> possibilities = valuesUnmapped.tailSet((char) (a[i] + 1)).headSet(b[i]);
                        if (!possibilities.isEmpty()) {
                            char toAdd = possibilities.first();
                            template.put(s[i], toAdd);
                            valuesUnmapped.remove(toAdd);
                            possible = true;
                        } else if (valuesUnmapped.contains(a[i])) {
                            //make copies if failure
                            Map<Character, Character> templateCP = new HashMap<>();
                            SortedSet<Character> valuesUnmappedCP = new TreeSet<>();
                            templateCP.putAll(template);
                            valuesUnmappedCP.addAll(valuesUnmapped);
                            // s surely less than string b, need to ensure s is greater than or equal string a
                            template.put(s[i], a[i]);
                            valuesUnmapped.remove(a[i]);
                            possible = greaterThanAssignment(i, s, a, template, valuesUnmapped);
                            if (!possible) {
                                template = templateCP;
                                valuesUnmapped = valuesUnmappedCP;
                            }
                        }
                        if (!possible && valuesUnmapped.contains(b[i])) {
                            template.put(s[i], b[i]);
                            valuesUnmapped.remove(b[i]);
                            // s surely more than string a, need to ensure s is less than or equal string b
                            possible = lessThanAssignment(i, s, b, template, valuesUnmapped);
                        }
                    }
                    break;
                }
            }
            if (possible) {
                pw.println("YES");
                Queue<Character> unused = new LinkedList<>();
                unused.addAll(valuesUnmapped);
                for (char i = 'a'; i < maxLetter; i++) {
                    if (!template.containsKey(i)) {
                        template.put(i, unused.poll());
                    }
                    pw.write(template.get(i));
                }
                pw.println();
            } else {
                pw.println("NO");
            }
        }
        pw.flush();
        br.close();
        pw.close();
    }

    //assign so that s is greater than a
    private static boolean greaterThanAssignment(int stIndex, char[] s, char[] a, Map<
            Character, Character> template, SortedSet<Character> valuesUnmapped) {
        for (int j = stIndex + 1; j < s.length; j++) {
            if (template.containsKey(s[j])) {
                if (template.get(s[j]) < a[j]) {
                    return false;
                } else if (template.get(s[j]) > a[j]) {
                    return true;
                }
            } else {
                SortedSet<Character> pos = valuesUnmapped.tailSet(a[j]);
                if (pos.isEmpty()) {
                    return false;
                }
                char toAdd = pos.last();
                template.put(s[j], toAdd);
                valuesUnmapped.remove(toAdd);
                if (toAdd != a[j]) {
                    return true;
                }
            }
        }
        return true;
    }

    //assign so that s is less than b
    private static boolean lessThanAssignment(int stIndex, char[] s, char[] b, Map<
            Character, Character> template, SortedSet<Character> valuesUnmapped) {
        for (int j = stIndex + 1; j < s.length; j++) {
            if (template.containsKey(s[j])) {
                if (template.get(s[j]) < b[j]) {
                    return true;
                } else if (template.get(s[j]) > b[j]) {
                    return false;
                }
            } else {
                SortedSet<Character> pos = valuesUnmapped.headSet((char) (1 + b[j]));
                if (pos.isEmpty()) {
                    return false;
                }
                char toAdd = pos.first();
                template.put(s[j], toAdd);
                valuesUnmapped.remove(toAdd);
                if (toAdd != b[j]) {
                    return true;
                }
            }
        }
        return true;
    }
}
