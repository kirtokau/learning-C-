package com.lang;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFDateUtil;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.streaming.SXSSFWorkbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.joda.time.DateTime;
import org.junit.Test;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Date;

public class ExcelRead {
    String PATH="D:\\poi_easyexcel\\lang_poi";
     @Test
    public void testRead03() throws Exception {
         //1、创建一个工作簿,使用Excel能操作的这边都可以操作
         //2、获取文件流
         FileInputStream inputStream = new FileInputStream(PATH + "统计表03.xls");
         Workbook workbook = new HSSFWorkbook(inputStream);
         //2、创建一个工作簿，使用excel能操作的这边他都可以操作
         //  Sheet sheet = workbook.createSheet("统计表");
         //得到表
         Sheet sheet = workbook.getSheetAt(0);
         //得到行
         Row row = sheet.getRow(0);
         //得到列
         Cell cell = row.getCell(1);
         //getStringCellValue 字符串类型
        System.out.println(cell.getStringCellValue());
        //System.out.println(cell.getNumericCellValue() );
         

         inputStream.close();
     }
    @Test
    public void testRead07() throws Exception {
        //1、创建一个工作簿,使用Excel能操作的这边都可以操作
        //2、获取文件流
        FileInputStream inputStream = new FileInputStream(PATH + "统计表07.xls");
        Workbook workbook = new XSSFWorkbook(inputStream);
        //2、创建一个工作簿，使用excel能操作的这边他都可以操作
        //  Sheet sheet = workbook.createSheet("统计表");
        //得到表
        Sheet sheet = workbook.getSheetAt(0);
        //得到行
        Row row = sheet.getRow(0);
        //得到列
        Cell cell = row.getCell(1);
        //getStringCellValue 字符串类型
        System.out.println(cell.getStringCellValue());
        //System.out.println(cell.getNumericCellValue() );


        inputStream.close();
    }
    @Test
    public void testCellType() throws IOException {
        String PATH="D:\\poi_easyexcel\\lang_poi\\";
        FileInputStream inputStream = new FileInputStream(PATH + "明细表2.xls");
        Workbook workbook = new HSSFWorkbook(inputStream);
        Sheet sheet=workbook.getSheetAt(0);
        //获取标题内容
        Row rowTitle=sheet.getRow(0);
        if(rowTitle!=null)
        {
            int cellCount= rowTitle.getPhysicalNumberOfCells();
            for(int cellNum=0;cellNum<cellCount;cellNum++)
            {
                Cell cell = rowTitle.getCell(cellNum);
                if(cell!=null)
                {
                    int cellType = cell.getCellType();
                    String CellValue = cell.getStringCellValue();
                    System.out.println(CellValue);

               }

            }

        }
       //获取表中内容
        int rowCount = sheet.getPhysicalNumberOfRows();
        for(int rowNum=1;rowNum<rowCount;rowNum++)
        {
            Row rowData = sheet.getRow(rowNum);
            if(rowData!=null)
            {
                //读取列
                int cellCount = rowTitle.getPhysicalNumberOfCells();
                for(int cellNum=0;cellNum<cellCount;cellNum++)
                {
                    System.out.println("["+(rowNum+1)+"-"+(cellNum+1)+"]");
                    Cell cell = rowData.getCell(cellNum);
                    //匹配列的数据类型
                    if(cell!=null)
                    {
                        int cellType = cell.getCellType();
                        String cellValue="";
                        switch(cellType)
                        {
                            case HSSFCell.CELL_TYPE_STRING:;//字符串
                                System.out.println("【String】");
                                cellValue = cell.getStringCellValue();
                                break;
                            case HSSFCell.CELL_TYPE_BOOLEAN:;//布尔
                                System.out.println("【BOOLEAN】");
                                cellValue = String.valueOf(cell.getBooleanCellValue());
                                break;
                            case HSSFCell.CELL_TYPE_BLANK:;//空
                                System.out.println("【BLANK】");
                                cellValue = String.valueOf(cell.getBooleanCellValue());
                                break;
                            case HSSFCell.CELL_TYPE_NUMERIC:;//数字（日期，普通数字）
                                System.out.println("【NUMERIC】");
                                if(HSSFDateUtil.isCellDateFormatted(cell))//日期
                                {
                                    System.out.println("【日期】");
                                    Date date=cell.getDateCellValue();
                                    cellValue=new DateTime(date).toString("yyy-MM-dd");

                                }else
                                {
                                    //不是日期格式，防止数字过长
                                    System.out.println("【转换成字符串输出】");
                                    cell.setCellType(HSSFCell.CELL_TYPE_STRING);
                                    //cellValue = String.valueOf(cell.getBooleanCellValue());
                                    cellValue=String.valueOf(cell.toString());
                                    //cellValue = cell.getStringCellValue();

                                }
                                break;

                            case HSSFCell.CELL_TYPE_ERROR:;
                                System.out.println("【数据类型错误】");
                                break;
                        }
                        System.out.println(cellValue);


                    }


                }
            }

        }
        inputStream.close();

    }
     }


