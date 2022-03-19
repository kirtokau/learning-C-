package com.lang;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.streaming.SXSSFWorkbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.joda.time.DateTime;
import org.junit.Test;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import static com.sun.deploy.uitoolkit.ToolkitStore.dispose;

public class ExcelWrite {
    String PATH="D:\\poi_easyexcel\\lang_poi";
    @Test
    public void testwtrite03() throws Exception {
        //1、创建一个工作簿
        Workbook workbook=new HSSFWorkbook();
        //2、创建一个工作表
        Sheet sheet=workbook.createSheet("统计表");
        //3、创建一个行
        Row row1=sheet.createRow(0);
        //4、创建一个单元格(1,1)
        Cell cell11 = row1.createCell(0);
        cell11.setCellValue("统计人数");
        Cell cell12 = row1.createCell(1);
        cell12.setCellValue("666");
        //第二行(2,1)
        Row row2 = sheet.createRow(1);
        Cell cell21 = row2.createCell(0);
        cell21.setCellValue("统计时间");
        //(2,2)
        Cell cell22 = row2.createCell(1);
        String time = new DateTime().toString("yyy-MM-dd HH:mm:ss");
        cell22.setCellValue(time);
        //生成一张表（IO流） 03版本以xls结尾
        FileOutputStream fileOutputStream = new FileOutputStream(PATH + "统计表03.xls");
        //输出
        workbook.write(fileOutputStream);
        //关闭流
        fileOutputStream.close();
        System.out.println("统计表03生成完毕！");



    }
    @Test
    public void testwtrite07() throws Exception {
        //1、创建一个工作簿07
        Workbook workbook=new XSSFWorkbook();
        //2、创建一个工作表
        Sheet sheet=workbook.createSheet("07统计表");
        //3、创建一个行
        Row row1=sheet.createRow(0);
        //4、创建一个单元格(1,1)
        Cell cell11 = row1.createCell(0);
        cell11.setCellValue("统计人数");
        Cell cell12 = row1.createCell(1);
        cell12.setCellValue("666");
        //第二行(2,1)
        Row row2 = sheet.createRow(1);
        Cell cell21 = row2.createCell(0);
        cell21.setCellValue("统计时间");
        //(2,2)
        Cell cell22 = row2.createCell(1);
        String time = new DateTime().toString("yyy-MM-dd HH:mm:ss");
        cell22.setCellValue(time);
        //生成一张表（IO流） 07版本以xlsx结尾
        FileOutputStream fileOutputStream = new FileOutputStream(PATH + "统计表07.xls");
        //输出
        workbook.write(fileOutputStream);
        //关闭流
        fileOutputStream.close();
        System.out.println("统计表07生成完毕！");



    }
    @Test
    public void testwtrite03BigData() throws IOException {
        //计算时间差
        long begin=System.currentTimeMillis();
        //创建一个工作簿
        Workbook workbook=new HSSFWorkbook();
        //创建表
        Sheet sheet = workbook.createSheet();
        //写入数据
        for(int rowNum=0;rowNum<65536;rowNum++)
        {
            Row row=sheet.createRow(rowNum);
            for(int cellNum=0;cellNum<10;cellNum++)
            {
                Cell cell=row.createCell(cellNum);
                cell.setCellValue(cellNum);

            }
        }
        System.out.println("over");
        FileOutputStream fileOutputStream = new FileOutputStream(PATH + "testWrie03BigData.xls");
        workbook.write(fileOutputStream);
        fileOutputStream.close();
        long end=System.currentTimeMillis();
        System.out.println((double)(end-begin)/1000);
    }
    //耗时较长 优化，缓存
    @Test
    public void testwtrite07BigData() throws IOException {
        //计算时间差
        long begin=System.currentTimeMillis();
        //创建一个工作簿
        Workbook workbook=new SXSSFWorkbook();
        //创建表
        Sheet sheet = workbook.createSheet();
        //写入数据
        for(int rowNum=0;rowNum<65537;rowNum++)
        {
            Row row=sheet.createRow(rowNum);
            for(int cellNum=0;cellNum<10;cellNum++)
            {
                Cell cell=row.createCell(cellNum);
                cell.setCellValue(cellNum);

            }
        }
        System.out.println("over");
        FileOutputStream fileOutputStream = new FileOutputStream(PATH + "testWrie07BigData.xlsx");
        workbook.write(fileOutputStream);
        fileOutputStream.close();
        long end=System.currentTimeMillis();
        System.out.println((double)(end-begin)/1000);
    }
    @Test
    public void testwtrite07BigDataS() throws Exception {
        //计算时间差
        long begin=System.currentTimeMillis();
        //创建一个工作簿
        Workbook workbook=new SXSSFWorkbook();
        //创建表
        Sheet sheet = workbook.createSheet();
        //写入数据
        for(int rowNum=0;rowNum<100000;rowNum++)
        {
            Row row=sheet.createRow(rowNum);
            for(int cellNum=0;cellNum<10;cellNum++)
            {
                Cell cell=row.createCell(cellNum);
                cell.setCellValue(cellNum);

            }
        }
        System.out.println("over");
        FileOutputStream fileOutputStream = new FileOutputStream(PATH + "testWrie07BigDataS.xlsx");
        workbook.write(fileOutputStream);
        fileOutputStream.close();
        //清除临时文件
        SXSSFWorkbook workbook1 = (SXSSFWorkbook) workbook;
        workbook1.dispose();
        long end=System.currentTimeMillis();
        System.out.println((double)(end-begin)/1000);
    }
}
