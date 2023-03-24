
import java.sql.*;


public class CRUDUtils1 {

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

    public static void query(String sql,Object...params) {
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
            ResultSet rs=pstmt.executeQuery();

            //处理结果集
            // 获取列数
            int columnCount = rs.getMetaData().getColumnCount();

            // 遍历每一行
            while (rs.next()) {
                // 遍历每一列
                for (int i = 1; i <= columnCount; i++) {
                    // 获取列名和值
                    String columnName = rs.getMetaData().getColumnName(i);
                    Object value = rs.getObject(i);

                    // 处理结果
                    System.out.print(columnName + ": " + value + "\t");
                }
                System.out.println();
            }
            jdbcUtils.close(con,pstmt,rs);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
