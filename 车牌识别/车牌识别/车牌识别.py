import xlwt
work_book = xlwt.Workbook(encoding='utf-8')
sheet = work_book.add_sheet('ͣ������Ϣ��')
sheet.write(0,0,'����')
sheet.write(0,1,'���ƺ�')
work_book.save('Excel��,xls')

