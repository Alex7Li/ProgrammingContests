package misc.jobquestions;

import java.io.*;
import java.util.Arrays;

public class Symcode {

    //files for I/O
    private final static String inputFileLocation = "src/misc/symcode-in.txt";
    private final static String outputFileLocation = "src/misc/symcode-out.txt";

    //character array representing the character encoding scheme.
    private final static char[] code = "symantec".toCharArray();

    /**
     * Removes whitespace and encodes a line of input
     * according to the Symcode encoding scheme.
     *
     * @param input
     * @return the encoded string
     */
    private String encodeLine(String input) {
        char[] inputChars = input.trim().toCharArray();

        // determine the length of the bits array (ignoring padding)
        int bitsLength = inputChars.length * 8 + inputChars.length % 3;

        // create the array bits from the bits of inputChars, with 1
        // corresponding to true, and 0 to false.
        boolean[] bits = new boolean[bitsLength];
        for (int i = 0; i < inputChars.length; i++) {
            //get the bits of a char, padding to 8 bits in case of shorter numbers
            char[] bitStr = String.format("%8s", Integer.toBinaryString(inputChars[i]))
                    .replace(' ', '0').toCharArray();
            for (int j = 0; j < bitStr.length; j++) {
                bits[8 * i + j] = (bitStr[j] == '1');
            }
        }

        // encode the bits according to the scheme
        char[] encodedChars = new char[8 * ((2+inputChars.length) / 3)];
        // pad extra characters
        Arrays.fill(encodedChars,'$');
        for (int i = 0; i < bits.length; i += 3) {
            int index = 0;
            if (bits[i]) { index += 4; }
            if (bits[i + 1]) { index += 2; }
            if (bits[i + 2]) { index++; }
            encodedChars[i/3] = code[index];
        }
        return String.valueOf(encodedChars);
    }

    /**
     * Encodes the input file in inputFileLocation according to the
     * specified encoding, storing the result in outputFileLocation.
     *
     * @throws IOException
     */
    public void encodeFile() throws IOException {
        // get the input and output files from wherever.
        BufferedReader inputFile = new BufferedReader(new FileReader(new File(inputFileLocation)));
        PrintWriter outputFile = new PrintWriter(new BufferedWriter(new FileWriter(
                new File(outputFileLocation))));

        // for each line in the file, print the encoded version of the line
        inputFile.lines().map(this::encodeLine).forEach(outputFile::println);

        inputFile.close();
        outputFile.close();
    }

    // calls encodeFile
    public static void main(String[] args) {
        Symcode symEncoder = new Symcode();
        try {
            symEncoder.encodeFile();
        } catch (IOException e) {
            System.err.println("There was an error reading/writing to files.");
            e.printStackTrace();
        }
    }
}

