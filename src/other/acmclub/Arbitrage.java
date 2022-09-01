package other.acmclub;

import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

class QueueElement {
  QueueElement prev;
  double ratio;
  int ind;


  public QueueElement(QueueElement prev, int ind, double ratio) {
    this.ratio = ratio;
    this.ind = ind;
    this.prev = prev;
  }
}
//https://open.kattis.com/problems/arbitrage
public class Arbitrage {
  public static void find_cycle(int start, double[][] edgeMatrix, int n_currency, String[] currency_names) {
    Queue<QueueElement> Q = new ArrayDeque<QueueElement>();
    Q.add(new QueueElement(null, start, 0.0));
    while (true) {
      QueueElement next = Q.poll();
      if (next.ind == start && next.prev != null) {
        if (next.ratio > 0) {
          System.out.println(Math.exp(next.ratio));
          while (next.prev != null) {
            System.out.print(currency_names[next.ind] + " ");
            next = next.prev;
          }
          return;
        }
        continue;
      }
      for (int i = 0; i < edgeMatrix.length; i++) {
        if (edgeMatrix[next.ind][i] != Double.NEGATIVE_INFINITY) {
          Q.add(new QueueElement(next, i, next.ratio + edgeMatrix[next.ind][i]));
        }
      }
    }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n_currency = Integer.parseInt(sc.nextLine());
        do {
          Map<String, Integer> currencies = new HashMap<>();
          String[] currency_names = new String[n_currency];
            for (int i = 0; i < n_currency; i++) {
              String name = sc.next();
              currencies.put(name, i);
              currency_names[i] = name;
            }
            double[][] edgeMatrix = new double[n_currency][n_currency];
            double[][] origEdgeMatrix = new double[n_currency][n_currency];
            for (int i = 0; i < edgeMatrix.length; i++) {
                for (int j = 0; j < edgeMatrix[i].length; j++) {
                    if (i != j) {
                        edgeMatrix[i][j] = Double.NEGATIVE_INFINITY;
                    }
                    origEdgeMatrix[i][j] = Double.NEGATIVE_INFINITY;
                }
            }
            int n_rates = Integer.parseInt(sc.next());
            for (int i = 0; i < n_rates; i++) {
                String cur1 = sc.next();
                int node1 = currencies.get(cur1);
                String cur2 = sc.next();
                int node2 = currencies.get(cur2);
                String[] ratioStr = sc.next().split(":");
                double ratio = Double.parseDouble(ratioStr[1]) / Double.parseDouble(ratioStr[0]);
                edgeMatrix[node1][node2] = Math.log(ratio);
                origEdgeMatrix[node1][node2] = edgeMatrix[node1][node2];
            }
            for (int i = 0; i < edgeMatrix.length; i++) {
                for (int j = 0; j < edgeMatrix.length; j++) {
                    for (int k = 0; k < edgeMatrix.length; k++) {
                        //check if there is bigger gain j->i->k
                        if (edgeMatrix[j][i] + edgeMatrix[i][k] > edgeMatrix[j][k]) {
                            edgeMatrix[j][k] = edgeMatrix[j][i] + edgeMatrix[i][k];
                        }
                    }
                }
            }
            int arbitrage = -1;
            for (int i = 0; i < edgeMatrix.length; i++) {
                if (edgeMatrix[i][i] > 1e-7) {
                  arbitrage = i;
                  System.err.println(currency_names[i]);
                }
            }
            if (arbitrage != -1) {
                find_cycle(arbitrage, origEdgeMatrix, n_currency, currency_names);
                System.out.println("Arbitrage");
            } else {
                System.out.println("Ok");
            }
            n_currency = Integer.parseInt(sc.next());
        } while (n_currency != 0);
        sc.close();
    }
}
