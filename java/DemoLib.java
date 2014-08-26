public class DemoLib {

  public native long   getToken(long seed);
  public native String getMessage(long token);
  public native String getMessageQuoted(long token);

  public static void main(String[] args) {
    DemoLib dlib = new DemoLib();
    System.out.printf("Token: %8d\n", dlib.getToken(1));
    System.out.printf("Token: %8d\n", dlib.getToken(10));
    System.out.printf("Token: %8d\n", dlib.getToken(20));
    System.out.printf("Token: %8d\n", dlib.getToken(55));
  }

  static {
    System.loadLibrary("demo");
  }
}
