package tools;
import static org.junit.Assert.assertTrue;

import org.junit.jupiter.api.Test;

class SegmentTreeTest {

	@Test
	void segTreeTest() {
		int[] a = {4,7,1,0,-4,15};
		SegmentTree st = new SegmentTree(a);
		assertTrue(st.get(1,2) == 7);
		assertTrue(st.get(0,1) == 4);
		assertTrue(st.get(3,6) == 11);
		st.update(0, 0);
		assertTrue(st.get(0,1) == 0);
		assertTrue(st.get(0,2) == 7);
		assertTrue(st.get(0,3) == 8);
	}

	@Test
	void segTreeTest2() {
		int[] a = {-1,2,-4,8,-16,32,-64,128};
		SegmentTree st = new SegmentTree(a);
		assertTrue(st.get(0,2) == 1);
		assertTrue(st.get(2,4) == 4);
		assertTrue(st.get(4,6) == 16);
		assertTrue(st.get(6,8) == 64);
		assertTrue(st.get(2,6) == 20);
		assertTrue(st.get(0,8) == 1+4+16+64);
		st.update(4, 0);
		assertTrue(st.get(0,2) == 1);
		assertTrue(st.get(2,4) == 4);
		assertTrue(st.get(4,6) == 32);
		assertTrue(st.get(6,8) == 64);
		assertTrue(st.get(2,6) == 36);
		assertTrue(st.get(0,8) == 1+4+32+64);
		st.update(2, 100);
		assertTrue(st.get(0,2) == 1);
		assertTrue(st.get(2,4) == 108);
		assertTrue(st.get(4,6) == 32);
		assertTrue(st.get(6,8) == 64);
		assertTrue(st.get(2,6) == 108+32);
		assertTrue(st.get(0,8) == 1+108+32+64);
	}
}
