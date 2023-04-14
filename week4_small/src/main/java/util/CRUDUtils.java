package util;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class CRUDUtils {

    public static Integer update(String sql,Object... params) {
        try {
            //获取执行对象
            Connection con=jdbcUtils.getConnection();
            PreparedStatement pstmt=con.prepareStatement(sql);
            //设置占位符
            int parameterCount = pstmt.getParameterMetaData().getParameterCount();
            if (parameterCount != params.length) {
                throw new RuntimeException("参数不匹配");
            }
            for (int i = 0; i < params.length; i++) {
                pstmt.setObject(i+1,params[i]);
            }
            //执行
            Integer re=pstmt.executeUpdate();
            //释放资源
            jdbcUtils.close(con,pstmt,null);
            return re;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    public static ResultSet query(String sql,Object...params) {
        try {
            //获取执行对象
            Connection con=jdbcUtils.getConnection();
            PreparedStatement pstmt=con.prepareStatement(sql);
            //设置占位符
            int parameterCount = pstmt.getParameterMetaData().getParameterCount();
            if (parameterCount != params.length) {
                throw new RuntimeException("参数不匹配");
            }
            for (int i = 0; i < params.length; i++) {
                pstmt.setObject(i+1,params[i]);
            }

            return pstmt.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
