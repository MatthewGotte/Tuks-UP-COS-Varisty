import { Component } from '@angular/core';
import { ActionSheetController } from '@ionic/angular';
import { ChartDataset } from 'chart.js';
import html2canvas from 'html2canvas';
import jsPDF from 'jspdf';
import { productData } from '../Data/productData';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  tableData: any;
  barChartData: ChartDataset[] = [];
  barChartLabels: Array<any> = [];
  barChartOptions: any = {
    responsive: true,
  };
  barChartLegend: boolean = true;
  barChartType: string = 'bar';
  showData: boolean = false;
  products: any[] = [];
  values: number[] = [];

// -- ------------------------------------------------
// DO NOT EDIT ABOVE THIS LINE
// --------------------------------------------------
  constructor(private actionSheetController: ActionSheetController) {}

  async presentActionSheet() {

    // -- ------------------------------------------------
    // COMPLETE Q1.1 BELOW THIS LINE
      const actionSheet = await this.actionSheetController.create({
        header: 'Data Action Sheet',
        cssClass: 'my-custom-class',
        buttons: [
        {
          text: 'Show Data',
          icon: 'analytics-outline',
          handler: () => {
            this.generateReport();
          }
        }, {
          text: 'Cancel',
          icon: 'close',
          role: 'cancel',
        }]
      });
      await actionSheet.present();
    // --------------------------------------------------

  }

  generateReport() {
    this.showData = true;

    // -- ------------------------------------------------
    // COMPLETE Q1.2 BELOW THIS LINE
      const data = productData;
      data.forEach((product: any) => {
        this.products.push(product.name);
        this.values.push(product.value);
      });
      this.barChartData = [{
        data: this.values,
        label: 'Sales',
        backgroundColor: 'rgb(0,183,255)'
      }];
      this.barChartLabels = this.products;
      this.generateTable();
    // --------------------------------------------------

  }

  openPDF(){
    let Data = document.getElementById('htmlData')!;
    // Canvas Options
    html2canvas(Data).then((canvas) => {

      let fileWidth = 210;
      let fileHeight = (canvas.height * fileWidth) / canvas.width;

      const contentDataURL = canvas.toDataURL('image/png');

    // -- ------------------------------------------------
    // COMPLETE Q1.3 BELOW THIS LINE
      const PDF = new jsPDF({
        orientation: 'p',
        unit: 'mm',
        format: 'a4'
      });

      const topPosition = 10;
      const leftPosition = 0;

      PDF.addImage(contentDataURL, 'PNG', leftPosition, topPosition, fileWidth, fileHeight);
      PDF.save('Graph.pdf');
    // --------------------------------------------------


    });
  }


// -- ------------------------------------------------
// DO NOT EDIT BELOW THIS LINE
// --------------------------------------------------
  generateTable() {
    this.tableData = productData;
  }
}
