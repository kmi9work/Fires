namespace Fire_forecast
{
    partial class Dannie
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.dg_dannie = new System.Windows.Forms.DataGridView();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tb_supp_1 = new System.Windows.Forms.TextBox();
            this.b_algoritm_apriori = new System.Windows.Forms.Button();
            this.dg_pravila = new System.Windows.Forms.DataGridView();
            this.dg_fires_1 = new System.Windows.Forms.DataGridView();
            this.dg_fires_2 = new System.Windows.Forms.DataGridView();
            this.dg_fires_3 = new System.Windows.Forms.DataGridView();
            this.dg_fires_4 = new System.Windows.Forms.DataGridView();
            this.dg_fires_5 = new System.Windows.Forms.DataGridView();
            this.label4 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.panel1 = new System.Windows.Forms.Panel();
            this.num_urovni_min = new System.Windows.Forms.NumericUpDown();
            this.num_urovni_max = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.tb_supp_2 = new System.Windows.Forms.TextBox();
            this.tb_supp_3 = new System.Windows.Forms.TextBox();
            this.tb_supp_5 = new System.Windows.Forms.TextBox();
            this.tb_supp_4 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dg_dannie)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_pravila)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_5)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_urovni_min)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_urovni_max)).BeginInit();
            this.SuspendLayout();
            // 
            // dg_dannie
            // 
            this.dg_dannie.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_dannie.Location = new System.Drawing.Point(6, 3);
            this.dg_dannie.Name = "dg_dannie";
            this.dg_dannie.Size = new System.Drawing.Size(869, 561);
            this.dg_dannie.TabIndex = 0;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(74, 5);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 13);
            this.label3.TabIndex = 14;
            this.label3.Text = "Уровни:";
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.Color.Gray;
            this.label1.Location = new System.Drawing.Point(23, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 20);
            this.label1.TabIndex = 13;
            this.label1.Text = "Уровень";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // tb_supp_1
            // 
            this.tb_supp_1.Location = new System.Drawing.Point(94, 77);
            this.tb_supp_1.Name = "tb_supp_1";
            this.tb_supp_1.Size = new System.Drawing.Size(62, 20);
            this.tb_supp_1.TabIndex = 12;
            this.tb_supp_1.Text = "10";
            // 
            // b_algoritm_apriori
            // 
            this.b_algoritm_apriori.Location = new System.Drawing.Point(41, 222);
            this.b_algoritm_apriori.Name = "b_algoritm_apriori";
            this.b_algoritm_apriori.Size = new System.Drawing.Size(121, 30);
            this.b_algoritm_apriori.TabIndex = 11;
            this.b_algoritm_apriori.Text = "Пуск";
            this.b_algoritm_apriori.UseVisualStyleBackColor = true;
            this.b_algoritm_apriori.Click += new System.EventHandler(this.b_algoritm_apriori_Click);
            // 
            // dg_pravila
            // 
            this.dg_pravila.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_pravila.Location = new System.Drawing.Point(6, 6);
            this.dg_pravila.Name = "dg_pravila";
            this.dg_pravila.Size = new System.Drawing.Size(928, 524);
            this.dg_pravila.TabIndex = 16;
            this.dg_pravila.Visible = false;
            // 
            // dg_fires_1
            // 
            this.dg_fires_1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_fires_1.Location = new System.Drawing.Point(501, 315);
            this.dg_fires_1.Name = "dg_fires_1";
            this.dg_fires_1.Size = new System.Drawing.Size(192, 156);
            this.dg_fires_1.TabIndex = 17;
            this.dg_fires_1.Visible = false;
            // 
            // dg_fires_2
            // 
            this.dg_fires_2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_fires_2.Location = new System.Drawing.Point(501, 315);
            this.dg_fires_2.Name = "dg_fires_2";
            this.dg_fires_2.Size = new System.Drawing.Size(192, 156);
            this.dg_fires_2.TabIndex = 18;
            this.dg_fires_2.Visible = false;
            // 
            // dg_fires_3
            // 
            this.dg_fires_3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_fires_3.Location = new System.Drawing.Point(501, 315);
            this.dg_fires_3.Name = "dg_fires_3";
            this.dg_fires_3.Size = new System.Drawing.Size(192, 156);
            this.dg_fires_3.TabIndex = 19;
            this.dg_fires_3.Visible = false;
            // 
            // dg_fires_4
            // 
            this.dg_fires_4.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_fires_4.Location = new System.Drawing.Point(501, 315);
            this.dg_fires_4.Name = "dg_fires_4";
            this.dg_fires_4.Size = new System.Drawing.Size(192, 156);
            this.dg_fires_4.TabIndex = 20;
            this.dg_fires_4.Visible = false;
            // 
            // dg_fires_5
            // 
            this.dg_fires_5.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_fires_5.Location = new System.Drawing.Point(501, 315);
            this.dg_fires_5.Name = "dg_fires_5";
            this.dg_fires_5.Size = new System.Drawing.Size(192, 156);
            this.dg_fires_5.TabIndex = 21;
            this.dg_fires_5.Visible = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(86, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(10, 13);
            this.label4.TabIndex = 24;
            this.label4.Text = "-";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(3, 2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1160, 562);
            this.tabControl1.TabIndex = 25;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.dg_dannie);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1152, 536);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Исходные данные";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.panel1);
            this.tabPage2.Controls.Add(this.dg_pravila);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1152, 536);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Правила";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label9);
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.b_algoritm_apriori);
            this.panel1.Controls.Add(this.tb_supp_5);
            this.panel1.Controls.Add(this.tb_supp_4);
            this.panel1.Controls.Add(this.tb_supp_3);
            this.panel1.Controls.Add(this.tb_supp_2);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.num_urovni_max);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.tb_supp_1);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.num_urovni_min);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Location = new System.Drawing.Point(940, 6);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(200, 255);
            this.panel1.TabIndex = 25;
            // 
            // num_urovni_min
            // 
            this.num_urovni_min.Location = new System.Drawing.Point(36, 21);
            this.num_urovni_min.Name = "num_urovni_min";
            this.num_urovni_min.Size = new System.Drawing.Size(43, 20);
            this.num_urovni_min.TabIndex = 26;
            this.num_urovni_min.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.num_urovni_min.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // num_urovni_max
            // 
            this.num_urovni_max.Location = new System.Drawing.Point(101, 21);
            this.num_urovni_max.Name = "num_urovni_max";
            this.num_urovni_max.Size = new System.Drawing.Size(43, 20);
            this.num_urovni_max.TabIndex = 27;
            this.num_urovni_max.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.num_urovni_max.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.BackColor = System.Drawing.Color.Gray;
            this.label5.Location = new System.Drawing.Point(93, 49);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 20);
            this.label5.TabIndex = 28;
            this.label5.Text = "Поддержка min,%";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tb_supp_2
            // 
            this.tb_supp_2.Location = new System.Drawing.Point(94, 103);
            this.tb_supp_2.Name = "tb_supp_2";
            this.tb_supp_2.Size = new System.Drawing.Size(62, 20);
            this.tb_supp_2.TabIndex = 29;
            this.tb_supp_2.Text = "10";
            // 
            // tb_supp_3
            // 
            this.tb_supp_3.Location = new System.Drawing.Point(94, 129);
            this.tb_supp_3.Name = "tb_supp_3";
            this.tb_supp_3.Size = new System.Drawing.Size(62, 20);
            this.tb_supp_3.TabIndex = 30;
            this.tb_supp_3.Text = "10";
            // 
            // tb_supp_5
            // 
            this.tb_supp_5.Location = new System.Drawing.Point(94, 181);
            this.tb_supp_5.Name = "tb_supp_5";
            this.tb_supp_5.Size = new System.Drawing.Size(62, 20);
            this.tb_supp_5.TabIndex = 32;
            this.tb_supp_5.Text = "10";
            // 
            // tb_supp_4
            // 
            this.tb_supp_4.Location = new System.Drawing.Point(94, 155);
            this.tb_supp_4.Name = "tb_supp_4";
            this.tb_supp_4.Size = new System.Drawing.Size(62, 20);
            this.tb_supp_4.TabIndex = 31;
            this.tb_supp_4.Text = "10";
            // 
            // label6
            // 
            this.label6.BackColor = System.Drawing.Color.LightGray;
            this.label6.Location = new System.Drawing.Point(30, 77);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 20);
            this.label6.TabIndex = 33;
            this.label6.Text = "1";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            this.label2.BackColor = System.Drawing.Color.LightGray;
            this.label2.Location = new System.Drawing.Point(30, 103);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 20);
            this.label2.TabIndex = 34;
            this.label2.Text = "2";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.BackColor = System.Drawing.Color.LightGray;
            this.label7.Location = new System.Drawing.Point(30, 129);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 20);
            this.label7.TabIndex = 35;
            this.label7.Text = "3";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label8
            // 
            this.label8.BackColor = System.Drawing.Color.LightGray;
            this.label8.Location = new System.Drawing.Point(30, 155);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(49, 20);
            this.label8.TabIndex = 36;
            this.label8.Text = "4";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label9
            // 
            this.label9.BackColor = System.Drawing.Color.LightGray;
            this.label9.Location = new System.Drawing.Point(30, 181);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(49, 20);
            this.label9.TabIndex = 37;
            this.label9.Text = "5";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Dannie
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1164, 615);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.dg_fires_5);
            this.Controls.Add(this.dg_fires_4);
            this.Controls.Add(this.dg_fires_3);
            this.Controls.Add(this.dg_fires_2);
            this.Controls.Add(this.dg_fires_1);
            this.Name = "Dannie";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dg_dannie)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_pravila)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_fires_5)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_urovni_min)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_urovni_max)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dg_dannie;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tb_supp_1;
        private System.Windows.Forms.Button b_algoritm_apriori;
        private System.Windows.Forms.DataGridView dg_pravila;
        private System.Windows.Forms.DataGridView dg_fires_1;
        private System.Windows.Forms.DataGridView dg_fires_2;
        private System.Windows.Forms.DataGridView dg_fires_3;
        private System.Windows.Forms.DataGridView dg_fires_4;
        private System.Windows.Forms.DataGridView dg_fires_5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        public System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown num_urovni_max;
        private System.Windows.Forms.NumericUpDown num_urovni_min;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox tb_supp_5;
        private System.Windows.Forms.TextBox tb_supp_4;
        private System.Windows.Forms.TextBox tb_supp_3;
        private System.Windows.Forms.TextBox tb_supp_2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label2;
    }
}

