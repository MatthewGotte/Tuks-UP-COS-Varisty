import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

import { FormsModule } from '@angular/forms';
import { LoginPageComponent } from './login-page/login-page.component';
import { TrendingPageComponent } from './trending-page/trending-page.component';

import { CommonModule } from '@angular/common';

const routes: Routes = [
  {
    path: 'home',
    loadChildren: () => import('./home/home.module').then( m => m.HomePageModule)
  },
  {
    path: 'login', component: LoginPageComponent
  },
  {
    path: 'trending', component: TrendingPageComponent
  },
  {
    path: '',
    redirectTo: 'login',
    pathMatch: 'full'
  },
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule, FormsModule, CommonModule],
  declarations: [LoginPageComponent, TrendingPageComponent],
})
export class AppRoutingModule { }
