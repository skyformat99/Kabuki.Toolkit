
package hal;

public class String
{
    String (byte[] bytes);
    String (byte[] bytes, CharSet charset);
    String (byte[] bytes, int offset, int length);
    String (byte[] bytes, int offset, int length, CharSet charset);
    String (byte[] bytes, int offset, int length, String charsetName);
    String (byte[] bytes, String charsetName);
    String (char[] value);
    String (char[] value, int offset, int count);
    String (int[] codePoints, int offset, int count);
    
    String (String original);
    String (StringBuffer buffer);
    String (StringBuilder builder);
    
    void increaseBufferSize (int lengthToAdd);
    
    int  cursor ();
    void moveCurrsorLeft ();
    void moveCurrsorRight ();
    
    void delete ();
    void backspace ();
    
    bool add (char   newText);
    bool add (char[] newText);
    bool add (Text   newText);
    
    bool insert (char   newText);
    bool insert (char[] newText);
    bool insert (String newText);
    
    void update ();
    
    char charAt (int index);
    
    int codePointAt (int index);
    int codePointBefore (int index);
    int codePointCount (int beginIndex, int endIndex);
    
    int compare (String anotherString);
    int compareIgnoreCase (String str);
    
    String concat (String str);
    
    bool contains (CharSequence s);
    
    bool contentEquals (CharSequence cs);
    bool contentEquals (StringBuffer sb);
    
    bool endsWith (String suffix);
    
    bool equals (Object anObject);
    bool equalsIgnoreCase (String anotherString);
    
    byte[] getBytes ();
    byte[] getBytes (CharSet charset);
    byte[] getBytes (String charsetName);
    
    void getChars (int srcBegin, int srcEnd, char[] dst, int dstBegin);
    int hashCode ();
    
    int indexOf (int ch);
    int indexOf (int ch, int fromIndex);
    int indexOf (String str);
    int indexOf (String str, int fromIndex);
    
    String  intern ();
    bool isEmpty ();
    
    int lastIndexOf (int ch);
    int lastIndexOf (int ch, int fromIndex);
    int lastIndexOf (String str);
    int lastIndexOf (String str, int fromIndex);
    
    int length ();
    
    bool matches (String regex);
    int offsetByCodePoints (int index, int codePointOffset);
    
    bool regionMatches (bool ignoreCase, int toffset, String other, int ooffset, int len);
    bool regionMatches (int toffset, String other, int ooffset, int len);
    
    String replace (char oldChar, char newChar);
    String replace (CharSequence target, CharSequence replacement);
    String replaceAll (String regex, String replacement);
    String replaceFirst (String regex, String replacement);
    
    String[] split (String regex);
    String[] split (String regex, int limit);
    
    bool startsWith (String prefix);
    bool startsWith (String prefix, int toffset);
    
    CharSequence    subSequence (int beginIndex, int endIndex);
    
    String  substring (int beginIndex);
    String  substring (int beginIndex, int endIndex);
    
    char[]  toCharArray ();
    String  toLowerCase ();
    String  toLowerCase (Local locale);
    String  toString ();
    String  toUpperCase ();
    String  toUpperCase (Local locale);
    String  trim ();
    
    static String copyValueOf (char[] data);
    static String copyValueOf (char[] data, int offset, int count);
    
    static String format (Locale l, String format, Object... args);
    static String format (String format, Object... args);
    
    static String valueOf (bool b);
    static String valueOf (char c);
    static String valueOf (char[] data);
    static String valueOf (char[] data, int offset, int count);
    static String valueOf (double d);
    static String valueOf (float f);
    static String valueOf (int i);
    static String valueOf (long l);
    static String valueOf (Object obj);
}
