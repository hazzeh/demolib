public class DemoLib {

  public native long   getToken(long seed);
  public native String getMessage(long token);
  public native String getMessageQuoted(long token);

  public static void main(String[] args) {
    DemoLib dlib = new DemoLib();
    System.out.printf("Distance: %16d\n", dlib.getToken(10));
  }

  static {
    System.loadLibrary("jdemolib");
  }
}
