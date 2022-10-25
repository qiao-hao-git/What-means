import xlwt
work_book = xlwt.Workbook(encoding='utf-8')
sheet = work_book.add_sheet('停车场信息表')
sheet.write(0,0,'车辆')
sheet.write(0,1,'车牌号')
work_book.save('Excel表,xls')

