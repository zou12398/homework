import java.io.FileInputStream;
import java.sql.*;
import java.util.Properties;


public class jdbcUtils {
    private static final String url;
    private static final String username;
    private static final String password;

    static {
        try {
            Properties prop=new Properties();
            prop.load(new FileInputStream("src/MysqlUser.properties"));
            //1.注册驱动
            Class.forName(prop.getProperty("driver"));

            //2.读取配置文件
            url = prop.getProperty("url");
            username = prop.getProperty("username");
            password = prop.getProperty("password");

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }

    public static void close(Connection con,PreparedStatement sta, ResultSet set) throws SQLException {
        if(set!=null) {
            set.close();
        }
        if(sta!=null) {
            sta.close();
        }
        if(con!=null) {
            con.close();
        }
    }

}
