package misc.aoc;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AOC2018Day10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = 0;
        List<Point> points = new ArrayList<Point>();
        String line = sc.nextLine();
        while (!line.equals("")) {
            int x = Integer.parseInt(line.substring(10,16).trim());
            int y = Integer.parseInt(line.substring(17,24).trim());
            int vx = Integer.parseInt(line.substring(36,38).trim());
            int vy = Integer.parseInt(line.substring(40,42).trim());
            Point p = new Point(x,y,vx,vy);
            points.add(p);
            line = sc.nextLine();
        }
        printPic(points, 10227);
    }
    private static void printPic(List<Point> points, int turns){
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        boolean[][] image = new boolean[400][200];
        for(Point p : points){
            System.out.println(p.x+p.vx*turns);
            System.out.println(p.y+p.vy*turns);
            image[p.x+p.vx*turns][p.y+p.vy*turns]=true;
        }
        try {
            for (int i = 0; i < image[0].length; i++) {
                for (int j = 0; j < image.length; j++) {
                    bw.write(image[j][i] ? '*' : '.');
                }
                bw.newLine();
            }
            bw.flush();
        }catch (IOException e){
            e.printStackTrace();
        }
        }
    private static class Point
    {
        int x;
        int y;
        int vx;
        int vy;
        public Point(int px, int py, int velx, int vely){
            x=px;
            y=py;
            vx=velx;
            vy=vely;
        }
    }

}
