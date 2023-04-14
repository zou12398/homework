package util;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import com.alibaba.druid.util.JdbcUtils;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;


public class jdbcUtils {
    private static DataSource dataSource;

    static {
        //数据源配置
        Properties prop = new Properties();
        //读取配置文件
        InputStream is = JdbcUtils.class.getResourceAsStream("/druids.properties");
        try {
            prop.load(is);
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            //返回的是DataSource
            dataSource = DruidDataSourceFactory.createDataSource(prop);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static Connection getConnection() throws SQLException {
        return dataSource.getConnection();
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
