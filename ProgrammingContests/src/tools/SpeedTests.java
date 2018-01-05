package tools;

public class SpeedTests {
	public static void main(String[] args) {
		System.out.println(sysOutMillion() + " " + stringBuilderMillion());
	}
	private static long stringBuilderMillion() {
		long star = System.currentTimeMillis();
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < 1000000; i++) {
			s.append(i + "\r\n");
		}
		System.out.println();
		long end = System.currentTimeMillis();
		return end - star;
	}
	public static long sysOutMillion(){
		long star = System.currentTimeMillis();
		for (int i = 0; i < 1000000; i++) {
			System.out.println(i);
		}
		System.out.println();
		long end = System.currentTimeMillis();
		return end - star;
	}
}
